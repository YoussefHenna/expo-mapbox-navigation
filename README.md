# Expo Mapbox Navigation

A simple Expo wrapper for Mapbox's navigation SDK's on Android and iOS

## Installation

### `@rnmapbox/maps`

This package relies on the installtion of `@rnmapbox/maps`, so you'll have to install and setup as explained in their [installtion instructions](https://rnmapbox.github.io/docs/install). The current version of **Expo Mapbox Navigation** package was developed and tested for Mapbox Maps version `11.11.0`, so that is the recommended version when setting up the maps package. It is possible that everything will work with a later version, but unlikely with a lower version. **However, make sure you explcitly set the version with `RNMapboxMapsVersion` because this package relies on this being set to work**

> [!NOTE]  
> Make sure to follow the instructions carefully and include the proper token in the config plugin and to call the `Mapbox.setAccessToken` function. You can be sure everything is good when you're able to render a map.

### Install package

Run this command to add the package

```
npx expo install @youssefhenna/expo-mapbox-navigation
```

### Configure package

In your `app.json` or `app.js`, you'll need to add a plugin for the package under the `plugins` entry with a valid mapbox access token (The one that starts with `pk.`). For the mapbox maps version, you have to use the same version set in the setup steps of `@rnmapbox/maps`.

```json
"plugins": [
    ...other plugins
     [
        "@youssefhenna/expo-mapbox-navigation",
        {
          "accessToken": "<YOUR_TOKEN>",
          "mapboxMapsVersion": "<MAPBOX_MAPS_VERSION>"
        }
      ]
]
```

Additionally you need to enable `useFrameworks` in your ios config. This can be achieved by using the `expo-build-properties` package and plugin as follows:

```json
"plugins": [
    ...other plugins
     [
        "expo-build-properties",
        {
          "ios": {
            "useFrameworks": "static"
          }
        }
      ],
]
```

### Usage

After getting location permissions you can render the navigation map as follows anywhere in the app

```
<MapboxNavigationView
    style={{ flex: 1 }}
    coordinates={coordinates} />
```

## Props

#### `coordinates`

An array of `{latitude: number, longitude: number}` objects. This creates a route passing through all the given coordinates. Requires at least 2 points for start and end destinations.

#### `waypointIndices`

An array of indices representing which of the coordinates is to be considered a waypoint/destination. By default all coordinates are considered waypoints (and show a waypoint indicator), passing this prop allows choosing which of the coordinates are waypoints. At least the first and last element need to be included in the array for a route to render.

#### `useRouteMatchingApi`

When enabled, uses Mapbox's Map Matching API to generate the route instead of the regular navigation route generation APIs. Enable this when you want a more explicit path determined by the coordinates. [Mapbox Map Matching API](https://docs.mapbox.com/api/navigation/map-matching/)

#### `locale`

A string representation of a locale/language code that adjusts the Map labels, directions, and voice where possible. By default, uses the devices locale.

#### `routeProfile`

The profile to use for route generation. `mapbox/driving-traffic` by default. See [here](https://docs.mapbox.com/api/navigation/directions/#routing-profiles) for details

#### `routeExcludeList`

An array of road types and locations to exclude from the route. See the `exclude` param [here](https://docs.mapbox.com/api/navigation/directions/#optional-parameters) for details.

#### `mapStyle`

The style of the Mapbox map. See [here](https://docs.mapbox.com/api/maps/styles/) for details.

#### `mute`

Whether the navigation audio is initially muted.

#### `vehicleMaxHeight`

The maximum height of the vehicle in meters. This is used to avoid routes with height restrictions.

#### `vehicleMaxWidth`

The maximum width of the vehicle in meters. This is used to avoid routes with width restrictions.

#### `customRasterSourceUrl`

The URL of a custom raster source to use for the map. Should be a template string with `{x}`, `{y}`, `{z}` placeholders.  
Example: `"https://tile.openstreetmap.org/{z}/{x}/{y}.png"`

#### `placeCustomRasterLayerAbove`

The ID of the layer above which the custom raster layer should be placed. Useful for controlling the rendering order of map layers.

#### `disableAlternativeRoutes`

If true, disables calculation and display of alternative routes. By default, alternative routes may be shown if available.

#### `onRouteProgressChanged`

Called when the user's progress on the route changes.
Provides an object in the `nativeEvent` of type:

```ts
{
  distanceRemaining: number;
  distanceTraveled: number;
  durationRemaining: number;
  fractionTraveled: number;
}
```

#### `onCancelNavigation`

Called when the cancel navigation button is clicked. The library does not handle cancellation automatically, use this callback to handle the cancellation behaviour.

#### `onWaypointArrival`

Called when arrived at one of the given waypoints.
On **Android ONLY** provides an object in the `nativeEvent` of type:

```ts
{
  distanceRemaining: number;
  distanceTraveled: number;
  durationRemaining: number;
  fractionTraveled: number;
}
```

#### `onFinalDestinationArrival`

Called when arrived at the final destination

#### `onRouteChanged`

Called when the route changes or reroutes

#### `onUserOffRoute`

Called when the user goes off route

#### `onRoutesLoaded`

Called when routes are finished loading.

## Running the example app

- Run `yarn` on the root directory
- `cd example`
- Run `yarn` on the example app
- Run the app using `npx expo run:android` / `npx expo run:ios`

## Note on Mapbox version updates (for collaborators)

The Android implmentation uses the gradle dependencies and can easily be updated to newer versions.

iOS, however, bundles the Mapbox Navigation SDK into the expo module to be used. As of the date of writing this, the Mapbox Navigation SDK v3 does not support cocoapods and only supports Swift package manager. There is no obvious way on how one can include a package from the Swift package manager into an Expo module, so I opted to bundle the `.xcframework` package instead.

> [!NOTE]  
> Cocoapods support is apparently comming soon. When that day comes, this process can be made much easier.

### Getting the `.xcframework` files

First make sure .netrc is configured with your mapbox credentials.

Clone https://github.com/mapbox/mapbox-navigation-ios from the desired version branch.

Use this modified `Package.swift` and update the versions according to the cloned branch. Checksum for `navNativeChecksum` will be incorrect. Run `swift build -c release` which will fail and give you the correct checksum to update with. After updating, proceed with steps, do not re-run.

```swift
// swift-tools-version:5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let (navNativeVersion, navNativeChecksum) = ("324.0.0", "f7c0b81c2092faf60eea32538e630e5b67bb7d032251548a2b38054d0ede90f6")

let mapsVersion: Version = "11.11.0"
let commonVersion: Version = "24.11.0"

let mapboxApiDownloads = "https://api.mapbox.com/downloads/v2"

let package = Package(
    name: "MapboxNavigation",
    defaultLocalization: "en",
    platforms: [.iOS(.v14)],
    products: [
        .library(
            name: "MapboxNavigationUIKit",
            targets: ["MapboxNavigationUIKit"]
        ),
        .library(
            name: "MapboxNavigationCore",
            targets: ["MapboxNavigationCore"]
        )
    ],
    dependencies: [
        .package(url: "https://github.com/mapbox/mapbox-maps-ios.git", exact: mapsVersion),
        .package(url: "https://github.com/mapbox/mapbox-common-ios.git", exact: commonVersion),
        .package(url: "https://github.com/mapbox/turf-swift.git", exact: "4.0.0")
    ],
    targets: [
        .target(
            name: "MapboxNavigationUIKit",
            dependencies: [
                "MapboxNavigationCore",
            ],
            exclude: ["Info.plist"],
            resources: [
                .copy("Resources/MBXInfo.plist"),
                .copy("Resources/PrivacyInfo.xcprivacy")
            ]
        ),
        .target(name: "_MapboxNavigationHelpers"),
        .target(
            name: "MapboxNavigationCore",
            dependencies: [
                .product(name: "MapboxCommon", package: "mapbox-common-ios"),
                "MapboxNavigationNative",
                "MapboxDirections",
                "_MapboxNavigationHelpers",
                .product(name: "MapboxMaps", package: "mapbox-maps-ios"),
            ],
            resources: [
                .process("Resources")
            ]
        ),
        .target(
            name: "MapboxDirections",
            dependencies: [
                .product(name: "Turf", package: "turf-swift"),
            ]
        ),
        navNativeBinaryTarget(
            name: "MapboxNavigationNative",
            version: navNativeVersion,
            checksum: navNativeChecksum
        ),
    ]
)

private func navNativeBinaryTarget(name: String, version: String, checksum: String) -> Target {
    let url = "\(mapboxApiDownloads)/dash-native/releases/ios/packages/\(version)/MapboxNavigationNative.xcframework.zip"
    return .binaryTarget(name: name, url: url, checksum: checksum)
}
```

Clone https://github.com/giginet/Scipio/ **inside** the cloned mapbox-navigation-ios repo. `cd` inside that repo and run `swift build -c release`.

While still in the Scipio repo run

```
swift run -c release scipio create ../ -f \
    --platforms iOS  \
    --only-use-versions-from-resolved-file \
    --enable-library-evolution \
    --support-simulators \
    --embed-debug-symbols \
    --verbose
```

Based on https://github.com/mapbox/mapbox-navigation-ios/issues/4703#issuecomment-2297452009
