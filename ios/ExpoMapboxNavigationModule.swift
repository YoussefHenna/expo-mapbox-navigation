import ExpoModulesCore

public class ExpoMapboxNavigationModule: Module {

  public func definition() -> ModuleDefinition {
    Name("ExpoMapboxNavigation")

    View(ExpoMapboxNavigationView.self) {
      Prop("waypoints") { (view: ExpoMapboxNavigationView, waypoints: Array<Dictionary<String, Any>>) in
         var points: Array<CLLocationCoordinate2D> = []
         for waypoint in waypoints {
            let longValue = waypoint["longitude"]
            let latValue = waypoint["latitude"]
            if let long = longValue as? Double, let lat = latValue as? Double {
                points.append(CLLocationCoordinate2D(latitude: lat, longitude: long))
            }
          }
          view.controller.setWaypoints(points: points) 
      }
    }
  }
}
