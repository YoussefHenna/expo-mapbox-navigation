import ExpoModulesCore

public class ExpoMapboxNavigationModule: Module {
  static var accessToken: String? = nil

  public func definition() -> ModuleDefinition {
    Name("ExpoMapboxNavigation")

    Function("setAccessToken") { (token: String) in
      ExpoMapboxNavigationModule.accessToken = token
    }

    View(ExpoMapboxNavigationView.self) {
      Prop("coordinates") { (view: ExpoMapboxNavigationView, coordinates: Array<Dictionary<String, Any>>) in
         var points: Array<CLLocationCoordinate2D> = []
         for coord in coordinates {
            let longValue = coord["longitude"]
            let latValue = coord["latitude"]
            if let long = longValue as? Double, let lat = latValue as? Double {
                points.append(CLLocationCoordinate2D(latitude: lat, longitude: long))
            }
          }
          view.controller.setCoordinates(points: points) 
      }
    }
  }
}
