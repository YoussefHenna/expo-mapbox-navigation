import ExpoModulesCore
import MapboxNavigationCore
import MapboxMaps
import MapboxNavigationUIKit
import MapboxDirections


class ExpoMapboxNavigationView: ExpoView {
    let controller = ExpoMapboxNavigationViewController()

    required init(appContext: AppContext? = nil) {
        super.init(appContext: appContext)
        clipsToBounds = true
        addSubview(controller.view)
    }
}


class ExpoMapboxNavigationViewController: UIViewController {
    var navigationProvider: MapboxNavigationProvider? = nil
    var mapboxNavigation: MapboxNavigation? = nil
    var routingProvider: RoutingProvider? = nil

    init() {
        super.init(nibName: nil, bundle: nil)
        if(ExpoMapboxNavigationModule.accessToken == nil){
            fatalError("Mapbox access token is not configured, make sure you set it by calling 'setAccessToken'")
        }
        navigationProvider = MapboxNavigationProvider(coreConfig: .init(
            credentials: .init(accessToken: ExpoMapboxNavigationModule.accessToken!) ,
            locationSource: .live
        ))
        mapboxNavigation = navigationProvider!.mapboxNavigation
        routingProvider = mapboxNavigation!.routingProvider()
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        fatalError("This controller should not be loaded through a story board")
    }


    func setCoordinates(points: Array<CLLocationCoordinate2D>) {
        let waypoints = points.map { Waypoint(coordinate: $0) }
        let routeOptions = NavigationRouteOptions(waypoints: waypoints)
        Task {
            switch await self.routingProvider!.calculateRoutes(options: routeOptions).result {
            case .failure(let error):
                print(error.localizedDescription)
            case .success(let navigationRoutes):
                let navigationOptions = NavigationOptions(
                    mapboxNavigation: self.mapboxNavigation!,
                    voiceController: self.navigationProvider!.routeVoiceController,
                    eventsManager: self.navigationProvider!.eventsManager()
                )

                 let navigationViewController = NavigationViewController(
                    navigationRoutes: navigationRoutes,
                    navigationOptions: navigationOptions
                )

                navigationViewController.delegate = self
                addChild(navigationViewController)
                view.addSubview(navigationViewController.view)
                navigationViewController.view.translatesAutoresizingMaskIntoConstraints = false
                NSLayoutConstraint.activate([
                    navigationViewController.view.leadingAnchor.constraint(equalTo: view.leadingAnchor, constant: 0),
                    navigationViewController.view.trailingAnchor.constraint(equalTo: view.trailingAnchor, constant: 0),
                    navigationViewController.view.topAnchor.constraint(equalTo: view.topAnchor, constant: 0),
                    navigationViewController.view.bottomAnchor.constraint(equalTo: view.bottomAnchor, constant: 0),
                ])
                didMove(toParent: self)
            }
        }
    }

}
extension ExpoMapboxNavigationViewController: NavigationViewControllerDelegate {
    func navigationViewController(_ navigationViewController: NavigationViewController, didRerouteAlong route: Route) {}

    func navigationViewControllerDidDismiss(
        _ navigationViewController: NavigationViewController,
        byCanceling canceled: Bool
    ) { }
}
