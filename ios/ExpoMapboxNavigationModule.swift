import ExpoModulesCore
import CoreLocation

public class ExpoMapboxNavigationModule: Module {

  public func definition() -> ModuleDefinition {
    Name("ExpoMapboxNavigation")

    View(ExpoMapboxNavigationView.self) {
      Events("onRouteProgressChanged", "onCancelNavigation", "onWaypointArrival", "onFinalDestinationArrival", "onRouteChanged", "onUserOffRoute", "onRoutesLoaded", "onRouteFailedToLoad")

      Prop("coordinates") { (view: ExpoMapboxNavigationView, coordinates: Array<Dictionary<String, Any>>) in
         var points: Array<CLLocationCoordinate2D> = []
         for coordinate in coordinates {
            let longValue = coordinate["longitude"]
            let latValue = coordinate["latitude"]
            if let long = longValue as? Double, let lat = latValue as? Double {
                points.append(CLLocationCoordinate2D(latitude: lat, longitude: long))
            }
          }
          view.controller.setCoordinates(coordinates: points)
      }

      Prop("vehicleMaxHeight") { (view: ExpoMapboxNavigationView, maxHeight: Double?) in
          view.controller.setVehicleMaxHeight(maxHeight: maxHeight)
      }

      Prop("vehicleMaxWidth") { (view: ExpoMapboxNavigationView, maxWidth: Double?) in
          view.controller.setVehicleMaxWidth(maxWidth: maxWidth)
      }

      Prop("locale") { (view: ExpoMapboxNavigationView, locale: String?) in
          view.controller.setLocale(locale: locale)
      }

      Prop("useRouteMatchingApi"){ (view: ExpoMapboxNavigationView, useRouteMatchingApi: Bool?) in
          view.controller.setIsUsingRouteMatchingApi(useRouteMatchingApi: useRouteMatchingApi)
      }

      Prop("waypointIndices"){ (view: ExpoMapboxNavigationView, indices: Array<Int>?) in
          view.controller.setWaypointIndices(waypointIndices: indices)
      }

      Prop("routeProfile"){ (view: ExpoMapboxNavigationView, profile: String?) in
          view.controller.setRouteProfile(profile: profile)
      }

      Prop("routeExcludeList"){ (view: ExpoMapboxNavigationView, excludeList: Array<String>?) in
          view.controller.setRouteExcludeList(excludeList: excludeList)
      }

      Prop("mapStyle"){ (view: ExpoMapboxNavigationView, style: String?) in
          view.controller.setMapStyle(style: style)
      }

      Prop("mute"){ (view: ExpoMapboxNavigationView, isMuted: Bool?) in
          view.controller.setIsMuted(isMuted: isMuted)
      }

      Prop("initialLocation") { (view: ExpoMapboxNavigationView, location: Dictionary<String, Any>?) in
        if(location != nil){
          let longValue = location!["longitude"]
          let latValue = location!["latitude"]
          let zoomValue = location!["zoom"]
          if let long = longValue as? Double, let lat = latValue as? Double, let zoom = zoomValue as? Double? {
              view.controller.setInitialLocation(location: CLLocationCoordinate2D(latitude: lat, longitude: long), zoom: zoom)
          }
        }
      }

      Prop("customRasterSourceUrl") { (view: ExpoMapboxNavigationView, url: String?) in
        view.controller.setCustomRasterSourceUrl(url: url)
      }

      Prop("placeCustomRasterLayerAbove") { (view: ExpoMapboxNavigationView, layerId: String?) in
        view.controller.setPlaceCustomRasterLayerAbove(layerId: layerId)
      }

      Prop("disableAlternativeRoutes") { (view: ExpoMapboxNavigationView, disableAlternativeRoutes: Bool?) in
        view.controller.setDisableAlternativeRoutes(disableAlternativeRoutes: disableAlternativeRoutes)
      }

      Prop("followingZoom") { (view: ExpoMapboxNavigationView, followingZoom: Double?) in
        view.controller.setFollowingZoom(followingZoom: followingZoom)
      }

      AsyncFunction("recenterMap") { (view: ExpoMapboxNavigationView) in
        view.controller.recenterMap()
      }
    }
  }
}
