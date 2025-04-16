package expo.modules.mapboxnavigation

import androidx.lifecycle.LifecycleOwner
import androidx.lifecycle.lifecycleScope
import com.mapbox.geojson.Point
import com.mapbox.navigation.base.options.NavigationOptions
import com.mapbox.navigation.core.lifecycle.MapboxNavigationApp
import expo.modules.kotlin.modules.Module
import expo.modules.kotlin.modules.ModuleDefinition
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

class ExpoMapboxNavigationModule : Module() {
  private val activity
    get() = requireNotNull(appContext.activityProvider?.currentActivity)

  @com.mapbox.navigation.base.ExperimentalPreviewMapboxNavigationAPI
  override fun definition() = ModuleDefinition {
    Name("ExpoMapboxNavigation")

    OnActivityEntersForeground {
      (activity as LifecycleOwner).lifecycleScope.launch(Dispatchers.Main) {
        if (!MapboxNavigationApp.isSetup()) {
          MapboxNavigationApp.setup {
            NavigationOptions.Builder(activity.applicationContext).build()
          }
        }
        MapboxNavigationApp.attach(activity as LifecycleOwner)
      }
    }

    OnActivityEntersBackground {
      (activity as LifecycleOwner).lifecycleScope.launch(Dispatchers.Main) {
        MapboxNavigationApp.detach(activity as LifecycleOwner)
      }
    }

    View(ExpoMapboxNavigationView::class) {
      Events(
              "onRouteProgressChanged",
              "onCancelNavigation",
              "onWaypointArrival",
              "onFinalDestinationArrival",
              "onRouteChanged",
              "onUserOffRoute",
              "onRoutesLoaded"
      )

      Prop("coordinates") { view: ExpoMapboxNavigationView, coordinates: List<Map<String, Any>> ->
        val points = mutableListOf<Point>()
        for (coordinate in coordinates) {
          val longValue = coordinate.get("longitude")
          val latValue = coordinate.get("latitude")
          if (longValue is Double && latValue is Double) {
            points.add(Point.fromLngLat(longValue, latValue))
          }
        }
        view.setCoordinates(points)
      }

      Prop("vehicleMaxHeight") { view: ExpoMapboxNavigationView, maxHeight: Double? ->
        view.setVehicleMaxHeight(maxHeight)
      }

      Prop("vehicleMaxWidth") { view: ExpoMapboxNavigationView, maxWidth: Double? ->
        view.setVehicleMaxWidth(maxWidth)
      }

      Prop("waypointIndices") { view: ExpoMapboxNavigationView, indices: List<Int>? ->
        view.setWaypointIndices(indices)
      }

      Prop("locale") { view: ExpoMapboxNavigationView, localeStr: String? ->
        view.setLocale(localeStr)
      }

      Prop("useRouteMatchingApi") { view: ExpoMapboxNavigationView, useRouteMatchingApi: Boolean? ->
        view.setIsUsingRouteMatchingApi(useRouteMatchingApi)
      }

      Prop("routeProfile") { view: ExpoMapboxNavigationView, profile: String? ->
        view.setRouteProfile(profile)
      }

      Prop("routeExcludeList") { view: ExpoMapboxNavigationView, excludeList: List<String>? ->
        view.setRouteExcludeList(excludeList)
      }

      Prop("mapStyle") { view: ExpoMapboxNavigationView, style: String? -> view.setMapStyle(style) }

      Prop("mute") { view: ExpoMapboxNavigationView, isMuted: Boolean? -> view.setIsMuted(isMuted) }

      AsyncFunction("recenterMap") { view: ExpoMapboxNavigationView -> view.recenterMap() }
    }
  }
}
