package expo.modules.mapboxnavigation

import expo.modules.kotlin.modules.Module
import expo.modules.kotlin.modules.ModuleDefinition
import com.mapbox.navigation.base.options.NavigationOptions
import com.mapbox.navigation.core.lifecycle.MapboxNavigationApp
import com.mapbox.geojson.Point
import androidx.lifecycle.LifecycleOwner
import expo.modules.kotlin.jni.JavaScriptValue


class ExpoMapboxNavigationModule : Module() {
  private val activity
    get() = requireNotNull(appContext.activityProvider?.currentActivity)


  override fun definition() = ModuleDefinition { 

    Name("ExpoMapboxNavigation")

    OnActivityEntersForeground {
      if (!MapboxNavigationApp.isSetup()) {
            MapboxNavigationApp.setup {
                NavigationOptions.Builder(activity.applicationContext).build()
            }
        }
      MapboxNavigationApp.attach(activity as LifecycleOwner)
    }

    OnActivityEntersBackground {
      MapboxNavigationApp.detach(activity as LifecycleOwner)
    }

    View(ExpoMapboxNavigationView::class) {
      Prop("coordinates") { view: ExpoMapboxNavigationView, coordinates: List<Map<String, Any>> ->
        val points = mutableListOf<Point>()
        for (coordinate in coordinates) {
              val longValue = coordinate.get("longitude")
              val latValue = coordinate.get("latitude")
              if(longValue is Double && latValue is Double){
                points.add(Point.fromLngLat(longValue, latValue))
              }
            
        }
        view.setCoordinates(points)
      }
    }
  }
}
