# Expo Mapbox Navigation

A simple Expo wrapper for Mapbox's navigation SDK's on Android and iOS

## Installation

### `@rnmapbox/maps`

This package relies on the installtion of `@rnmapbox/maps`, so you'll have to install and setup as explained in their [installtion instructions](https://rnmapbox.github.io/docs/install). The current version of **Expo Mapbox Navigation** package was developed and tested for Mapbox Maps version `11.3.0`, so that is the recommended version when setting up the maps package. It is possible that everything will work with a later version, but unlikely with a lower version.

> [!NOTE]  
> Make sure to follow the instructions carefully and include the proper token in the config plugin and to call the `Mapbox.setAccessToken` function. You can be sure everything is good when you're able to render a map.

### Install package

Run this command to add the package

```
npx expo install @youssefhenna/expo-mapbox-navigation
```

### Configure package

In your `app.json` or `app.js`, you'll need to add a plugin for the package under the `plugins` entry with a valid mapbox access token (The one that starts with `pk.`).

```json
"plugins": [
    ...other plugins
     [
        "@youssefhenna/expo-mapbox-navigation",
        {
          "accessToken": "<YOUR_TOKEN>"
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
    waypoints={waypoints} />
```

## Props

#### `waypoints`

An array of `{latitude: number, longitude: number}` objects. This creates a route from the current location to pass through the given waypoints with a waypoint indicator on each point.

_more customization props and callback props to be added soon_

## Note on Mapbox version updates (for collaborators)

The Android implmentation uses the gradle dependencies and can easily be updated to newer versions.

iOS, however, bundles the Mapbox Navigation SDK into the expo module to be used. As of the date of writing this, the Mapbox Navigation SDK v3 does not support cocoapods and only supports Swift package manager. There is no obvious way on how one can include a package from the Swift package manager into an Expo module, so I opted to bundle the `.xcframework` package instead.

> [!NOTE]  
> Cocoapods support is apparently comming soon. When that day comes, this process can be made much easier.

### Getting the `.xcframework` files

To get the `.xcframework` files, I needed to use the mapbox api authenticated with my download token.

The API follows this format:
`https://api.mapbox.com/downloads/v2/<PATH>/releases/ios/packages/<VERSION>/<BINARY_NAME>.xcframework.zip`

- `PATH`: Different parts of the sdk are stored under different categories/folders in which this path determines
- `VERSION`: The version of the package to download
- `BINARY_NAME`: The name of the specfic binary to download

Specficially for navigation we need the binaries for:

- MapboxDirections
- MapboxMaps
- Turf
- MapboxNavigationCore
- \_MapboxNavigationUXPrivate
- MapboxNavigationUIKit

These all live under the `navsdk-v3-ios` as the `PATH`. For example:
https://api.mapbox.com/downloads/v2/navsdk-v3-ios/releases/ios/packages/3.1.1/MapboxDirections.xcframework.zip
downloads the MapboxDirections binary for the version `3.1.1`

To complete the api request, Basic authentication is required with the username `mapbox` and the password as the download token.

All this is based on the `Package.swift` file here: https://github.com/mapbox/mapbox-navigation-ios/blob/v3.1.1/Package.swift

Binary locations can change between each version on the next, so a slightly different set of steps might be needed
