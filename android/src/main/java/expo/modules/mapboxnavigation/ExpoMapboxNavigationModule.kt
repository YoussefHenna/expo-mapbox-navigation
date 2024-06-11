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

    OnCreate {
      if (!MapboxNavigationApp.isSetup()) {
            MapboxNavigationApp.setup {
                NavigationOptions.Builder(activity.applicationContext).build()
            }
        }
    }

    OnActivityEntersForeground {
      MapboxNavigationApp.attach(activity as LifecycleOwner)
    }

    OnActivityEntersBackground {
      MapboxNavigationApp.detach(activity as LifecycleOwner)
    }

    View(ExpoMapboxNavigationView::class) {
      Prop("coordinatesList") { view: ExpoMapboxNavigationView, coordinatesList: List<JavaScriptValue> ->
        val points = mutableListOf<Point>()
        for (coordinate in coordinatesList) {
            if(coordinate.isObject()){
              val coordObject = coordinate.getObject()
              val longValue = coordObject.getProperty("longitude")
              val latValue = coordObject.getProperty("latitude")
              if(longValue.isNumber() && latValue.isNumber()){
                points.add(Point.fromLngLat(longValue.getDouble(), latValue.getDouble()))
              }
            }
        }
        view.setCoordinatesList(points)
      }
    }
  }
}
