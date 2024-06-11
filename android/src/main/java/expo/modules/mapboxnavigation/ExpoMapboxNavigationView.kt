package expo.modules.mapboxnavigation

import android.content.Context
import android.widget.LinearLayout.LayoutParams;
import com.mapbox.api.directions.v5.models.DirectionsRoute
import com.mapbox.api.directions.v5.models.RouteOptions
import com.mapbox.common.location.Location
import com.mapbox.geojson.Point
import com.mapbox.maps.MapView
import com.mapbox.maps.plugin.animation.camera
import com.mapbox.maps.plugin.locationcomponent.location
import com.mapbox.maps.plugin.locationcomponent.OnIndicatorPositionChangedListener
import com.mapbox.navigation.base.extensions.applyDefaultNavigationOptions
import com.mapbox.navigation.base.route.NavigationRoute
import com.mapbox.navigation.base.route.NavigationRouterCallback
import com.mapbox.navigation.base.route.RouterFailure
import com.mapbox.navigation.base.route.RouterOrigin
import com.mapbox.navigation.base.trip.model.RouteProgress
import com.mapbox.navigation.core.directions.session.RoutesObserver
import com.mapbox.navigation.core.directions.session.RoutesUpdatedResult
import com.mapbox.navigation.core.lifecycle.MapboxNavigationApp
import com.mapbox.navigation.core.trip.session.LocationMatcherResult
import com.mapbox.navigation.core.trip.session.LocationObserver
import com.mapbox.navigation.core.trip.session.RouteProgressObserver
import com.mapbox.navigation.ui.maps.camera.data.MapboxNavigationViewportDataSource
import com.mapbox.navigation.ui.maps.camera.NavigationCamera
import com.mapbox.navigation.ui.maps.route.arrow.api.MapboxRouteArrowApi
import com.mapbox.navigation.ui.maps.route.arrow.api.MapboxRouteArrowView
import com.mapbox.navigation.ui.maps.route.arrow.model.RouteArrowOptions
import com.mapbox.navigation.ui.maps.route.line.api.MapboxRouteLineApi
import com.mapbox.navigation.ui.maps.route.line.api.MapboxRouteLineView
import com.mapbox.navigation.ui.maps.route.line.model.*
import expo.modules.kotlin.AppContext
import expo.modules.kotlin.views.ExpoView

class ExpoMapboxNavigationView(context: Context, appContext: AppContext) : ExpoView(context, appContext){
    
    private val mapboxNavigation = MapboxNavigationApp.current()

    private val mapView = MapView(context).also {
        it.layoutParams = LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT)
        addView(it)
    }
    private val mapboxMap = mapView.mapboxMap

    private val viewportDataSource = MapboxNavigationViewportDataSource(mapboxMap)
    private val navigationCamera = NavigationCamera(mapboxMap, mapView.camera, viewportDataSource)

    private val routeLineApiOptions = MapboxRouteLineApiOptions.Builder().build()
    private val routeLineApi = MapboxRouteLineApi(routeLineApiOptions)

    private val routeLineViewOptions = MapboxRouteLineViewOptions.Builder(context).build()
    private val routeLineView = MapboxRouteLineView(routeLineViewOptions)

    private val routeArrow = MapboxRouteArrowApi()
    private val routeArrowOptions = RouteArrowOptions.Builder(context).build()
    private val routeArrowView = MapboxRouteArrowView(routeArrowOptions)


    private val routesRequestCallback = object : NavigationRouterCallback {
        override fun onRoutesReady(routes: List<NavigationRoute>, @RouterOrigin routerOrigin: String) {
            mapboxNavigation?.setNavigationRoutes(routes)
        }
        override fun onCanceled(routeOptions: RouteOptions, @RouterOrigin routerOrigin: String) {}
        override fun onFailure(reasons: List<RouterFailure>, routeOptions: RouteOptions) {}
    }


    private val routesObserver = object : RoutesObserver {
        override fun onRoutesChanged(result: RoutesUpdatedResult) {
            // Handle viewport data source
            if (result.navigationRoutes.isNotEmpty()) {
                viewportDataSource.onRouteChanged(result.navigationRoutes.first())
                viewportDataSource.evaluate()
            } else {
                viewportDataSource.clearRouteData()
                viewportDataSource.evaluate()
            }

            // Handle route lines
            val alternativesMetadata = mapboxNavigation?.getAlternativeMetadataFor(result.navigationRoutes)
            routeLineApi.setNavigationRoutes(result.navigationRoutes, alternativesMetadata!!) { value ->
                routeLineView.renderRouteDrawData(mapboxMap!!.style!!, value)
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
                routeLineView.renderRouteLineUpdate(mapboxMap!!.style!!, result)
            }

            // Handle route arrows
            val updatedManeuverArrow = routeArrow.addUpcomingManeuverArrow(routeProgress)
		    routeArrowView.renderManeuverUpdate(mapboxMap!!.style!!, updatedManeuverArrow)
        }
    }

    private val locationObserver = object : LocationObserver {
        override fun onNewRawLocation(rawLocation: com.mapbox.common.location.Location) {
            viewportDataSource.onLocationChanged(rawLocation)
            viewportDataSource.evaluate()
        }

        override fun onNewLocationMatcherResult(locationMatcherResult: LocationMatcherResult) {}
    }

    private val onIndicatorPositionChangedListener = OnIndicatorPositionChangedListener { point ->
        val result = routeLineApi.updateTraveledRouteLine(point)
        routeLineView.renderRouteLineUpdate(mapboxMap!!.style!!, result)
    }


    fun setCoordinatesList(coordinatesList: List<Point>){
        mapboxNavigation?.requestRoutes(
            RouteOptions.builder()
                .applyDefaultNavigationOptions()
                .coordinatesList(coordinatesList)
                .build(),
            routesRequestCallback
        )
    }

    override fun onAttachedToWindow() {
        super.onAttachedToWindow()
        mapboxNavigation?.registerRoutesObserver(routesObserver)
        mapboxNavigation?.registerRouteProgressObserver(routeProgressObserver)
        mapboxNavigation?.registerLocationObserver(locationObserver)
        mapView.location.addOnIndicatorPositionChangedListener(onIndicatorPositionChangedListener)
    }

    override fun onDetachedFromWindow() {
        super.onDetachedFromWindow()
        mapboxNavigation?.unregisterRoutesObserver(routesObserver)
        mapboxNavigation?.unregisterRouteProgressObserver(routeProgressObserver)
        mapboxNavigation?.unregisterLocationObserver(locationObserver)
        mapView.location.removeOnIndicatorPositionChangedListener(onIndicatorPositionChangedListener)
        routeLineApi.cancel()
        routeLineView.cancel()
    }
}
