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

    override func layoutSubviews() {
        controller.view.frame = bounds
    }
}


class ExpoMapboxNavigationViewController: UIViewController {
    var navigationProvider: MapboxNavigationProvider? = nil
    var mapboxNavigation: MapboxNavigation? = nil
    var routingProvider: RoutingProvider? = nil

    init() {
        super.init(nibName: nil, bundle: nil)
        navigationProvider = MapboxNavigationProvider(coreConfig: .init(locationSource: .live))
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

                let navigationMapView = navigationViewController.navigationMapView
                navigationMapView!.puckType = .puck2D(.navigationDefault)
                navigationMapView!.mapView.mapboxMap.styleURI = .streets

                // Remove cancel button, navigation is not cancellable
                let cancelButton = navigationViewController.navigationView.bottomBannerContainerView.findViews(subclassOf: CancelButton.self)[0]
                cancelButton.removeFromSuperview()

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
                mapboxNavigation!.tripSession().startActiveGuidance(with: navigationRoutes, startLegIndex: 0)
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

extension UIView {
    func findViews<T: UIView>(subclassOf: T.Type) -> [T] {
        return recursiveSubviews.compactMap { $0 as? T }
    }

    var recursiveSubviews: [UIView] {
        return subviews + subviews.flatMap { $0.recursiveSubviews }
    }
}
