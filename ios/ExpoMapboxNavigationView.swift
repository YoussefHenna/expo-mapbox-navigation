import ExpoModulesCore
import MapboxNavigationCore
import MapboxMaps
import MapboxNavigationUIKit
import MapboxDirections


class ExpoRouteOptions: Codable {
    var maxHeight: Double?
    var maxWidth: Double?
}


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
    var currentCoordinates: Array<CLLocationCoordinate2D>? = nil
    var currentExpoRouteOptions: ExpoRouteOptions? = nil
    var currentWaypointIndices: Array<Int>? = nil
    var currentLocale: Locale = Locale.current
    var isUsingRouteMatchingApi: Bool = false
    var calculateRoutesTask: Task<Void, Error>? = nil

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


    func setCoordinates(coordinates: Array<CLLocationCoordinate2D>) {
        currentCoordinates = coordinates
        update()
    }

    func setRouteOptions(routeOptions: ExpoRouteOptions?) {
        currentExpoRouteOptions = routeOptions
        update()
    }

    func setLocale(locale: String?) {
        if(locale != nil){
            currentLocale = Locale(identifier: locale!)
        } else {
            currentLocale = Locale.current
        }
        update()
    }

    func setIsUsingRouteMatchingApi(useRouteMatchingApi: Bool?){
        isUsingRouteMatchingApi = useRouteMatchingApi ?? false
        update()
    }

    func setWaypointIndices(waypointIndices: Array<Int>?){
        currentWaypointIndices = waypointIndices
        update()
    }

    func update(){
        calculateRoutesTask?.cancel()

        if(currentCoordinates != nil){
            let waypoints = currentCoordinates!.enumerated().map {
                let index = $0
                let coordinate = $1
                var waypoint = Waypoint(coordinate: coordinate) 
                waypoint.separatesLegs = currentWaypointIndices == nil ? true : currentWaypointIndices!.contains(index)
                return waypoint
            }

            if(isUsingRouteMatchingApi){
                calculateMapMatchingRoutes(waypoints: waypoints)
            } else {
                calculateRoutes(waypoints: waypoints)
            }
        }
    }

    func calculateRoutes(waypoints: Array<Waypoint>){
            let routeOptions = RouteOptions(
                waypoints: waypoints, 
                profileIdentifier: .automobileAvoidingTraffic
            )
            if let maxHeight = currentExpoRouteOptions?.maxHeight {
                routeOptions.maximumHeight = Measurement(value: maxHeight, unit: UnitLength.meters)
            } else {
                routeOptions.maximumWidth = Measurement(value: 0.0, unit: UnitLength.meters)
            }

            if let maxWidth = currentExpoRouteOptions?.maxWidth {
                routeOptions.maximumWidth = Measurement(value: maxWidth, unit: UnitLength.meters)
            } else {
                routeOptions.maximumWidth = Measurement(value: 0.0, unit: UnitLength.meters)
            }
            
            calculateRoutesTask = Task {
                switch await self.routingProvider!.calculateRoutes(options: routeOptions).result {
                case .failure(let error):
                    print(error.localizedDescription)
                case .success(let navigationRoutes):
                    onRoutesCalculated(navigationRoutes: navigationRoutes)
                }
            }
        }

    func calculateMapMatchingRoutes(waypoints: Array<Waypoint>){
        let matchOptions = NavigationMatchOptions(
            waypoints: waypoints, 
            distanceUnit: currentLocale.usesMetricSystem ? LengthFormatter.Unit.meter : LengthFormatter.Unit.mile
        )
        calculateRoutesTask = Task {
            switch await self.routingProvider!.calculateRoutes(options: matchOptions).result {
            case .failure(let error):
                print(error.localizedDescription)
            case .success(let navigationRoutes):
                onRoutesCalculated(navigationRoutes: navigationRoutes)
            }
        }
    }

    func onRoutesCalculated(navigationRoutes: NavigationRoutes){
        let topBanner = TopBannerViewController()
        topBanner.instructionsBannerView.distanceFormatter.locale = currentLocale
        let bottomBanner = BottomBannerViewController()
        bottomBanner.distanceFormatter.locale = currentLocale
        bottomBanner.dateFormatter.locale = currentLocale

        let navigationOptions = NavigationOptions(
            mapboxNavigation: self.mapboxNavigation!,
            voiceController: self.navigationProvider!.routeVoiceController,
            eventsManager: self.navigationProvider!.eventsManager(),
            topBanner: topBanner,
            bottomBanner: bottomBanner
        )

        let navigationViewController = NavigationViewController(
            navigationRoutes: navigationRoutes,
            navigationOptions: navigationOptions
        )

        let navigationMapView = navigationViewController.navigationMapView
        navigationMapView!.puckType = .puck2D(.navigationDefault)

        navigationMapView!.mapView.mapboxMap.loadStyle(.streets, completion: { _ in
            navigationMapView!.localizeLabels(locale: self.currentLocale)
            do{
                try navigationMapView!.mapView.mapboxMap.localizeLabels(into: self.currentLocale)
            } catch {}
        })
 

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
