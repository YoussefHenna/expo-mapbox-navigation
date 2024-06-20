package expo.modules.mapboxnavigation

import android.content.Context
import android.content.res.Configuration
import android.content.res.Resources
import android.view.View;
import android.widget.TextView;
import androidx.constraintlayout.widget.ConstraintLayout
import androidx.constraintlayout.widget.ConstraintSet
import com.mapbox.api.directions.v5.models.DirectionsRoute
import com.mapbox.api.directions.v5.models.RouteOptions
import com.mapbox.bindgen.Expected
import com.mapbox.common.location.Location
import com.mapbox.geojson.Point
import com.mapbox.maps.EdgeInsets
import com.mapbox.maps.ImageHolder
import com.mapbox.maps.MapView
import com.mapbox.maps.plugin.animation.camera
import com.mapbox.maps.plugin.locationcomponent.location
import com.mapbox.maps.plugin.locationcomponent.OnIndicatorPositionChangedListener
import com.mapbox.maps.plugin.LocationPuck2D
import com.mapbox.maps.Style
import com.mapbox.navigation.base.extensions.applyDefaultNavigationOptions
import com.mapbox.navigation.base.formatter.DistanceFormatterOptions
import com.mapbox.navigation.base.route.NavigationRoute
import com.mapbox.navigation.base.route.NavigationRouterCallback
import com.mapbox.navigation.base.route.RouterFailure
import com.mapbox.navigation.base.route.RouterOrigin
import com.mapbox.navigation.base.trip.model.RouteProgress
import com.mapbox.navigation.core.directions.session.RoutesObserver
import com.mapbox.navigation.core.directions.session.RoutesUpdatedResult
import com.mapbox.navigation.core.formatter.MapboxDistanceFormatter
import com.mapbox.navigation.core.lifecycle.MapboxNavigationApp
import com.mapbox.navigation.core.trip.session.LocationMatcherResult
import com.mapbox.navigation.core.trip.session.LocationObserver
import com.mapbox.navigation.core.trip.session.RouteProgressObserver
import com.mapbox.navigation.core.trip.session.VoiceInstructionsObserver
import com.mapbox.navigation.tripdata.maneuver.api.MapboxManeuverApi
import com.mapbox.navigation.tripdata.progress.api.MapboxTripProgressApi
import com.mapbox.navigation.tripdata.progress.model.DistanceRemainingFormatter
import com.mapbox.navigation.tripdata.progress.model.EstimatedTimeToArrivalFormatter
import com.mapbox.navigation.tripdata.progress.model.TimeRemainingFormatter
import com.mapbox.navigation.tripdata.progress.model.TripProgressUpdateFormatter
import com.mapbox.navigation.tripdata.progress.model.TripProgressUpdateValue
import com.mapbox.navigation.ui.base.util.MapboxNavigationConsumer
import com.mapbox.navigation.ui.components.maneuver.model.ManeuverPrimaryOptions
import com.mapbox.navigation.ui.components.maneuver.model.ManeuverViewOptions
import com.mapbox.navigation.ui.components.maneuver.view.MapboxManeuverView
import com.mapbox.navigation.ui.components.maps.camera.view.MapboxRecenterButton
import com.mapbox.navigation.ui.components.maps.camera.view.MapboxRouteOverviewButton
import com.mapbox.navigation.ui.components.tripprogress.view.MapboxTripProgressView
import com.mapbox.navigation.ui.components.voice.view.MapboxSoundButton
import com.mapbox.navigation.ui.maps.camera.data.FollowingFrameOptions.FocalPoint
import com.mapbox.navigation.ui.maps.camera.data.MapboxNavigationViewportDataSource
import com.mapbox.navigation.ui.maps.camera.lifecycle.NavigationBasicGesturesHandler
import com.mapbox.navigation.ui.maps.camera.NavigationCamera
import com.mapbox.navigation.ui.maps.camera.transition.NavigationCameraTransitionOptions
import com.mapbox.navigation.ui.maps.location.NavigationLocationProvider
import com.mapbox.navigation.ui.maps.route.arrow.api.MapboxRouteArrowApi
import com.mapbox.navigation.ui.maps.route.arrow.api.MapboxRouteArrowView
import com.mapbox.navigation.ui.maps.route.arrow.model.RouteArrowOptions
import com.mapbox.navigation.ui.maps.route.line.api.MapboxRouteLineApi
import com.mapbox.navigation.ui.maps.route.line.api.MapboxRouteLineView
import com.mapbox.navigation.ui.maps.route.line.model.*
import com.mapbox.navigation.ui.maps.route.RouteLayerConstants.TOP_LEVEL_ROUTE_LINE_LAYER_ID
import com.mapbox.navigation.voice.api.*
import com.mapbox.navigation.voice.model.SpeechAnnouncement
import com.mapbox.navigation.voice.model.SpeechError
import com.mapbox.navigation.voice.model.SpeechValue
import com.mapbox.navigation.voice.model.SpeechVolume
import expo.modules.kotlin.AppContext
import expo.modules.kotlin.views.ExpoView
import java.util.Locale
import com.mapbox.navigation.ui.maps.camera.state.NavigationCameraState
import android.widget.ImageView

class ExpoMapboxNavigationView(context: Context, appContext: AppContext) : ExpoView(context, appContext){
    private val mapboxNavigation = MapboxNavigationApp.current()
    private var mapboxStyle: Style? = null
    private val navigationLocationProvider = NavigationLocationProvider()
    private val pixelDensity = Resources.getSystem().displayMetrics.density
    private val voiceInstructionsPlayer = MapboxVoiceInstructionsPlayer(context, Locale.US.toLanguageTag())
    private var isMuted = false

    private val parentConstraintLayout = ConstraintLayout(context).also {
        addView(it, LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT))   
    }

    private val mapViewId = 1
    private val mapView = MapView(context).apply {
        setId(mapViewId)
        parentConstraintLayout.addView(this)

        mapboxMap.loadStyle(Style.MAPBOX_STREETS) { style: Style ->
            mapboxStyle = style
        }

        location.apply {
            locationPuck = LocationPuck2D(
                bearingImage = ImageHolder.from(R.drawable.mapbox_navigation_puck_icon),
            )
            setLocationProvider(navigationLocationProvider)
            puckBearingEnabled = true
            enabled = true
        }     
    }

    private val mapboxMap = mapView.mapboxMap   

    private val overviewPadding: EdgeInsets by lazy {
        EdgeInsets(
            140.0 * pixelDensity,
            40.0 * pixelDensity,
            120.0 * pixelDensity,
            40.0 * pixelDensity
        )
    }
    private val landscapeOverviewPadding: EdgeInsets by lazy {
        EdgeInsets(
            30.0 * pixelDensity,
            380.0 * pixelDensity,
            110.0 * pixelDensity,
            20.0 * pixelDensity
        )
    }
    private val followingPadding: EdgeInsets by lazy {
        EdgeInsets(
            180.0 * pixelDensity,
            40.0 * pixelDensity,
            150.0 * pixelDensity,
            40.0 * pixelDensity
        )
    }
    private val landscapeFollowingPadding: EdgeInsets by lazy {
        EdgeInsets(
            30.0 * pixelDensity,
            380.0 * pixelDensity,
            110.0 * pixelDensity,
            40.0 * pixelDensity
        )
    }

    private val viewportDataSource = MapboxNavigationViewportDataSource(mapboxMap).apply {
        options.followingFrameOptions.focalPoint = FocalPoint(0.5, 0.9)
        if (context.resources.configuration.orientation == Configuration.ORIENTATION_LANDSCAPE) {
            followingPadding = landscapeFollowingPadding
            overviewPadding = landscapeOverviewPadding
        } else {
            followingPadding = followingPadding
            overviewPadding = overviewPadding
        }
    }
    private val navigationCamera = NavigationCamera(mapboxMap, mapView.camera, viewportDataSource).also {
        mapView.camera.addCameraAnimationsLifecycleListener(
            NavigationBasicGesturesHandler(it)
        )
    }

    private val maneuverViewId = 2
    private val maneuverView = MapboxManeuverView(context).apply {
        setId(maneuverViewId)
        parentConstraintLayout.addView(this)

        val maneuverViewOptions = ManeuverViewOptions.Builder()
            .primaryManeuverOptions(
                ManeuverPrimaryOptions.Builder()
                    .textAppearance(R.style.ManeuverTextAppearance)
                    .build()
            )
            .build()

        updateManeuverViewOptions(maneuverViewOptions)
    }

    private val tripProgressViewId = 3
    private val tripProgressView = MapboxTripProgressView(context).apply {
        setId(tripProgressViewId)
        parentConstraintLayout.addView(this)
    }

    private val soundButtonId = 4
    private val soundButton = MapboxSoundButton(context).apply {
        setId(soundButtonId)
        parentConstraintLayout.addView(this)
        findViewById<ImageView>(R.id.buttonIcon).setImageResource(R.drawable.icon_sound)
        setOnClickListener {
            voiceInstructionsPlayer.volume(SpeechVolume(if(isMuted) 1.0f else 0.0f))
            findViewById<ImageView>(R.id.buttonIcon).setImageResource(if(isMuted) R.drawable.icon_sound else R.drawable.icon_mute)
            isMuted = !isMuted
        }
    }

    private val overviewButtonId = 5
    private val overviewButton = MapboxRouteOverviewButton(context).apply {
        setId(overviewButtonId)
        parentConstraintLayout.addView(this)
        findViewById<ImageView>(R.id.buttonIcon).setImageResource(R.drawable.icon_overview)
        setOnClickListener {
            navigationCamera.requestNavigationCameraToOverview()
        }
    }
    
    private val recenterButtonId = 6
    private val recenterButton = MapboxRecenterButton(context).apply {
        setId(recenterButtonId)
        setVisibility(View.GONE)
        findViewById<ImageView>(R.id.buttonIcon).setImageResource(R.drawable.icon_compass)
        parentConstraintLayout.addView(this)
        setOnClickListener {
            navigationCamera.requestNavigationCameraToFollowing()
        }
    }

    private val parentConstraintSet = ConstraintSet().apply {
       // Add MapView constraints
        connect(mapViewId, ConstraintSet.TOP, ConstraintSet.PARENT_ID, ConstraintSet.TOP)
        connect(mapViewId, ConstraintSet.BOTTOM, tripProgressViewId, ConstraintSet.TOP)
        connect(mapViewId, ConstraintSet.START, ConstraintSet.PARENT_ID, ConstraintSet.START)
        connect(mapViewId, ConstraintSet.END, ConstraintSet.PARENT_ID, ConstraintSet.END)

        // Add ManeuverView constraints
        connect(maneuverViewId, ConstraintSet.TOP, mapViewId, ConstraintSet.TOP, (4 * pixelDensity).toInt())
        connect(maneuverViewId, ConstraintSet.START, ConstraintSet.PARENT_ID, ConstraintSet.START, (4 * pixelDensity).toInt())
        connect(maneuverViewId, ConstraintSet.END, ConstraintSet.PARENT_ID, ConstraintSet.END, (4 * pixelDensity).toInt())
        constrainHeight(maneuverViewId, ConstraintSet.WRAP_CONTENT)

        // Add TropProgressView constraints
        connect(tripProgressViewId, ConstraintSet.BOTTOM, ConstraintSet.PARENT_ID, ConstraintSet.BOTTOM)
        connect(tripProgressViewId, ConstraintSet.START, ConstraintSet.PARENT_ID, ConstraintSet.START)
        connect(tripProgressViewId, ConstraintSet.END, ConstraintSet.PARENT_ID, ConstraintSet.END)
        constrainHeight(tripProgressViewId, ConstraintSet.WRAP_CONTENT)
        constrainWidth(tripProgressViewId, ConstraintSet.MATCH_CONSTRAINT)

        // Add SoundButton constraints
        connect(soundButtonId, ConstraintSet.TOP, maneuverViewId, ConstraintSet.BOTTOM, (8 * pixelDensity).toInt())
        connect(soundButtonId, ConstraintSet.END, ConstraintSet.PARENT_ID, ConstraintSet.END, (16 * pixelDensity).toInt())
        constrainWidth(soundButtonId, ConstraintSet.WRAP_CONTENT)
        constrainHeight(soundButtonId, ConstraintSet.WRAP_CONTENT)


        // Add OverviewButton constraints
        connect(overviewButtonId, ConstraintSet.TOP, soundButtonId, ConstraintSet.BOTTOM, (8 * pixelDensity).toInt())
        connect(overviewButtonId, ConstraintSet.END, ConstraintSet.PARENT_ID, ConstraintSet.END, (16 * pixelDensity).toInt())
        constrainWidth(overviewButtonId, ConstraintSet.WRAP_CONTENT)
        constrainHeight(overviewButtonId, ConstraintSet.WRAP_CONTENT)

        // Add RecenterButton constraints
        connect(recenterButtonId, ConstraintSet.TOP, overviewButtonId, ConstraintSet.BOTTOM, (8 * pixelDensity).toInt())
        connect(recenterButtonId, ConstraintSet.END, ConstraintSet.PARENT_ID, ConstraintSet.END, (16 * pixelDensity).toInt())
        constrainWidth(recenterButtonId, ConstraintSet.WRAP_CONTENT)
        constrainHeight(recenterButtonId, ConstraintSet.WRAP_CONTENT)

        applyTo(parentConstraintLayout)
    }

    

    private val routeLineApiOptions = MapboxRouteLineApiOptions.Builder().build()
    private val routeLineApi = MapboxRouteLineApi(routeLineApiOptions)

    private val routeLineViewOptions = MapboxRouteLineViewOptions.Builder(context)
        .routeLineBelowLayerId("road-label")
        .build()
    private val routeLineView = MapboxRouteLineView(routeLineViewOptions)

    private val routeArrow = MapboxRouteArrowApi()
    private val routeArrowOptions = RouteArrowOptions.Builder(context)
        .withAboveLayerId(TOP_LEVEL_ROUTE_LINE_LAYER_ID)
        .build()
    private val routeArrowView = MapboxRouteArrowView(routeArrowOptions)

    private val distanceFormatter = DistanceFormatterOptions.Builder(context).build()
    private val maneuverApi = MapboxManeuverApi(MapboxDistanceFormatter(distanceFormatter))

    private val tripProgressFormatter = TripProgressUpdateFormatter.Builder(context)
			.distanceRemainingFormatter(DistanceRemainingFormatter(distanceFormatter))
	      	.timeRemainingFormatter(TimeRemainingFormatter(context))
			.estimatedTimeToArrivalFormatter(EstimatedTimeToArrivalFormatter(context))
			.build()
    private val tripProgressApi = MapboxTripProgressApi(tripProgressFormatter)

    private val speechApi = MapboxSpeechApi(context, Locale.US.toLanguageTag())
    private val voiceInstructionsPlayerCallback = MapboxNavigationConsumer<SpeechAnnouncement> { value ->
        speechApi.clean(value)
    }
    private val speechCallback = MapboxNavigationConsumer<Expected<SpeechError, SpeechValue>> { expected ->
        expected.fold(
            { error ->
                voiceInstructionsPlayer.play(
                    error.fallback,
                    voiceInstructionsPlayerCallback
                )
            },
            { value ->
                voiceInstructionsPlayer.play(
                    value.announcement,
                    voiceInstructionsPlayerCallback
                )
            }
        )
    }
    private val voiceInstructionsObserver = VoiceInstructionsObserver { voiceInstructions ->
        speechApi.generate(
            voiceInstructions,
            speechCallback
        )
    }


    private val routesRequestCallback = object : NavigationRouterCallback {
        override fun onRoutesReady(routes: List<NavigationRoute>, @RouterOrigin routerOrigin: String) {
            mapboxNavigation?.setNavigationRoutes(routes)
            mapboxNavigation?.startTripSession()
            navigationCamera.requestNavigationCameraToFollowing(
                stateTransitionOptions = NavigationCameraTransitionOptions.Builder()
                    .maxDuration(0) // instant transition
                    .build()
            )
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
            if(alternativesMetadata != null){
                routeLineApi.setNavigationRoutes(result.navigationRoutes, alternativesMetadata) { value ->
                    mapboxStyle?.let { routeLineView.renderRouteDrawData(it, value) }
                }
            }

            // Clear speech
            speechApi.cancel()
            voiceInstructionsPlayer.clear()

            // Add observer to navigation camera
            navigationCamera.registerNavigationCameraStateChangeObserver { navigationCameraState ->
                // shows/hide the recenter button depending on the camera state
                when (navigationCameraState) {
                    NavigationCameraState.TRANSITION_TO_FOLLOWING,
                    NavigationCameraState.FOLLOWING -> recenterButton.visibility = View.GONE
                    NavigationCameraState.TRANSITION_TO_OVERVIEW,
                    NavigationCameraState.OVERVIEW,
                    NavigationCameraState.IDLE -> recenterButton.visibility = View.VISIBLE
                }
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
                mapboxStyle?.let { routeLineView.renderRouteLineUpdate(it, result) }
            }

            // Handle route arrows
            val updatedManeuverArrow = routeArrow.addUpcomingManeuverArrow(routeProgress)
		    mapboxStyle?.let { routeArrowView.renderManeuverUpdate(it, updatedManeuverArrow) }

            // Handle manuevers
            val maneuvers = maneuverApi.getManeuvers(routeProgress)
            maneuverView.renderManeuvers(maneuvers)

            // Handle trip progress view
            tripProgressApi.getTripProgress(routeProgress).let { update: TripProgressUpdateValue ->
                tripProgressView.render(update)
            }

        }
    }

    private val locationObserver = object : LocationObserver {
        override fun onNewLocationMatcherResult(locationMatcherResult: LocationMatcherResult) {
            val enhancedLocation = locationMatcherResult.enhancedLocation

            // Update puck location
             navigationLocationProvider.changePosition(
                location = enhancedLocation,
                keyPoints = locationMatcherResult.keyPoints,
            )

            // Update viewport data source
            viewportDataSource.onLocationChanged(enhancedLocation)
            viewportDataSource.evaluate()
        }
        override fun onNewRawLocation(rawLocation: com.mapbox.common.location.Location) {}
    }

    private val onIndicatorPositionChangedListener = OnIndicatorPositionChangedListener { point ->
        val result = routeLineApi.updateTraveledRouteLine(point)
        mapboxStyle?.let { routeLineView.renderRouteLineUpdate(it, result) }
    }


    fun setCoordinates(coordinates: List<Point>){
        mapboxNavigation?.requestRoutes(
            RouteOptions.builder()
                .applyDefaultNavigationOptions()
                .coordinatesList(coordinates)
                .build(),
            routesRequestCallback
        )
    }

    override fun onAttachedToWindow() {
        super.onAttachedToWindow()
        mapboxNavigation?.registerRoutesObserver(routesObserver)
        mapboxNavigation?.registerRouteProgressObserver(routeProgressObserver)
        mapboxNavigation?.registerLocationObserver(locationObserver)
        mapboxNavigation?.registerVoiceInstructionsObserver(voiceInstructionsObserver)
        mapView.location.addOnIndicatorPositionChangedListener(onIndicatorPositionChangedListener)
    }

    override fun onDetachedFromWindow() {
        super.onDetachedFromWindow()
        mapboxNavigation?.unregisterRoutesObserver(routesObserver)
        mapboxNavigation?.unregisterRouteProgressObserver(routeProgressObserver)
        mapboxNavigation?.unregisterLocationObserver(locationObserver)
        mapboxNavigation?.unregisterVoiceInstructionsObserver(voiceInstructionsObserver)
        speechApi.cancel()
        voiceInstructionsPlayer.shutdown()
        mapView.location.removeOnIndicatorPositionChangedListener(onIndicatorPositionChangedListener)
        routeLineApi.cancel()
        routeLineView.cancel()
        maneuverApi.cancel()
    }
}
