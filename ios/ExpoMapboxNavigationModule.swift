import ExpoModulesCore

public class ExpoMapboxNavigationModule: Module {

  public func definition() -> ModuleDefinition {
    Name("ExpoMapboxNavigation")

    View(ExpoMapboxNavigationView.self) {
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

      Prop("locale") { (view: ExpoMapboxNavigationView, locale: String?) in
          view.controller.setLocale(locale: locale) 
      }

      Prop("routeOptions") { (view: ExpoMapboxNavigationView, routeOptions: Dictionary<String, Any>?) in 
          // Convert the dictionary to ExpoRouteOptions
          let rOpts = ExpoRouteOptions()
          if let routeOptions = routeOptions { // Safely unwrap routeOptions
              rOpts.maxHeight = routeOptions["maxHeight"] as? Double
              rOpts.maxWidth = routeOptions["maxWidth"] as? Double 
          }
          view.controller.setRouteOptions(routeOptions: rOpts) 
      }

      Prop("useRouteMatchingApi"){ (view: ExpoMapboxNavigationView, useRouteMatchingApi: Bool?) in
          view.controller.setIsUsingRouteMatchingApi(useRouteMatchingApi: useRouteMatchingApi) 
      }

      Prop("waypointIndices"){ (view: ExpoMapboxNavigationView, indices: Array<Int>?) in
          view.controller.setWaypointIndices(waypointIndices: indices) 
      }
    }
  }
}
