import ExpoModulesCore

public class ExpoMapboxNavigationModule: Module {
  public func definition() -> ModuleDefinition {
    Name("ExpoMapboxNavigation")

  
    View(ExpoMapboxNavigationView.self) {
      // Defines a setter for the `name` prop.
      Prop("name") { (view: ExpoMapboxNavigationView, prop: String) in
        print(prop)
      }
    }
  }
}
