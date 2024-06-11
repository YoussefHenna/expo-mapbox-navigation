package expo.modules.mapboxnavigation

import android.content.Context
import expo.modules.kotlin.AppContext
import expo.modules.kotlin.views.ExpoView
import com.mapbox.maps.MapView
import com.mapbox.navigation.core.lifecycle.MapboxNavigationApp
import com.mapbox.geojson.Point
import com.mapbox.navigation.base.route.NavigationRoute
import com.mapbox.navigation.base.route.RouterOrigin
import com.mapbox.api.directions.v5.models.RouteOptions
import com.mapbox.api.directions.v5.models.DirectionsRoute
import com.mapbox.navigation.base.route.NavigationRouterCallback
import com.mapbox.navigation.core.directions.session.RoutesObserver
import com.mapbox.navigation.core.trip.session.RouteProgressObserver
import com.mapbox.navigation.base.trip.model.RouteProgress
import com.mapbox.navigation.ui.maps.camera.data.MapboxNavigationViewportDataSource
import com.mapbox.navigation.ui.maps.route.line.api.MapboxRouteLineView
import com.mapbox.navigation.ui.maps.route.line.api.MapboxRouteLineViewOptions
import com.mapbox.navigation.ui.maps.route.line.api.MapboxRouteLineApiOptions
import com.mapbox.navigation.ui.maps.route.line.api.MapboxRouteLineApi
import com.mapbox.maps.plugin.location.OnIndicatorPositionChangedListener

class ExpoMapboxNavigationView(context: Context, appContext: AppContext) : ExpoView(context, appContext){
    
    private val mapBoxNavigation = MapboxNavigationApp.current()

    private val mapView = MapView(context)
    private val mapboxMap = mapView.mapBoxMap

    private val viewportDataSource = MapboxNavigationViewportDataSource(mapboxMap)
    private val navigationCamera = NavigationCamera(mapboxMap, mapView.camera, viewportDataSource)

    private val routeLineApiOptions = MapboxRouteLineApiOptions.Builder().build()
    private val routeLineApi = MapboxRouteLineApi(routeLineApiOptions)

    private val routeLineViewOptions = MapboxRouteLineViewOptions.Builder(context).build()
    private val routeLineView = MapboxRouteLineView(routeLineViewOptions)

    val routeArrow = MapboxRouteArrowApi()
    val routeArrowOptions = RouteArrowOptions.Builder(context).build()
    val routeArrowView = MapboxRouteArrowView(routeArrowOptions)


    private val routesRequestCallback = object : NavigationRouterCallback {
        override onRoutesReady(routes: List<NavigationRoute>, @RouterOrigin routerOrigin: String) {
            mapboxNavigation.setNavigationRoutes(routes)
        }
        override fun onCanceled(routeOptions: RouteOptions, routerOrigin: RouterOrigin) {}
        override fun onFailure(reasons: List<RouterFailure>, routeOptions: RouteOptions) {}
    }


    private val routesObserver = object : RoutesObserver {
        override fun onRoutesChanged(routes: List<DirectionsRoute>) {
            // Handle viewport data source
            if (routes.isNotEmpty()) {
                viewportDataSource.onRouteChanged(routes.first())
                viewportDataSource.evaluate()
            } else {
                viewportDataSource.clearRouteData()
                viewportDataSource.evaluate()
            }

            // Handle route lines
            val alternativesMetadata = mapboxNavigation.getAlternativeMetadataFor(result.navigationRoutes)
            routeLineApi.setNavigationRoutes(result.navigationRoutes, alternativesMetadata) { value ->
                routeLineView.renderRouteDrawData(mapStyle, value)
            }
        }
    }

    private val routeProgressObserver = object : RouteProgressObserver {
        override fun onRouteProgressChanged(routeProgress: RouteProgress) {
            // Handle viewport data source
            viewportDataSource.onRouteProgressChanged(routeProgress)
            viewportDataSource.evaluate()

            // Handle route lines
            routeLineApi.updateWithRouteProgress(routeProgress) { result ->
                routeLineView.renderRouteLineUpdate(mapStyle, result)
            }

            // Handle route arrows
            val updatedManeuverArrow = routeArrow.addUpcomingManeuverArrow(routeProgress)
		    routeArrowView.renderManeuverUpdate(mapStyle, updatedManeuverArrow)
        }
    }

    private val locationObserver = object : LocationObserver {
        override fun onEnhancedLocationChanged(enhancedLocation: Location, keyPoints: List<Location>) {
            viewportDataSource.onLocationChanged(enhancedLocation)
            viewportDataSource.evaluate()
        }

        override fun onRawLocationChanged(rawLocation: Location) {}
    }

    private val onIndicatorPositionChangedListener = OnIndicatorPositionChangedListener { point ->
        val result = routeLineApi.updateTraveledRouteLine(point)
        routeLineView.renderRouteLineUpdate(mapboxMap.style, result)
    }


    fun setCoordinatesList(coordinatesList: List<Point>){
        mapboxNavigation.requestRoutes(
            RouteOptions.builder()
                .applyDefaultNavigationOptions()
                .coordinatesList(coordinatesList)
                .build(),
            routesRequestCallback
        )
    }



  
    override fun onAttachedToWindow() {
        super.onAttachedToWindow()
        mapboxNavigation.registerRoutesObserver(routesObserver)
        mapboxNavigation.registerRouteProgressObserver(routeProgressObserver)
        mapboxNavigation.registerLocationObserver(locationObserver)
        mapboxNavigation.addOnIndicatorPositionChangedListener(onIndicatorPositionChangedListener)
    }

    override fun onDetachedFromWindow() {
        super.onDetachedFromWindow()
        mapboxNavigation.unregisterRoutesObserver(routesObserver)
        mapboxNavigation.unregisterRouteProgressObserver(routeProgressObserver)
        mapboxNavigation.unregisterLocationObserver(locationObserver)
        mapboxNavigation.removeOnIndicatorPositionChangedListener(onIndicatorPositionChangedListener)
        routeLineApi.cancel()
        routeLineView.cancel()
    }

    

  mapView.layoutParams = LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT)
    addView(mapView)

}
