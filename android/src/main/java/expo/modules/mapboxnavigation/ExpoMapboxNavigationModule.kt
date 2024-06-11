package expo.modules.mapboxnavigation

import expo.modules.kotlin.modules.Module
import expo.modules.kotlin.modules.ModuleDefinition
import com.mapbox.navigation.base.options.NavigationOptions
import com.mapbox.navigation.core.lifecycle.MapboxNavigationApp
import com.mapbox.geojson.Point


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
      MapboxNavigationApp.attach(activity)
    }

    OnActivityEntersBackground {
      MapboxNavigationApp.detach(activity)
    }

    View(ExpoMapboxNavigationView::class) {
      Prop("coordinatesList") { view: ExpoMapboxNavigationView, coordinatesList: List<JavaScriptValue> ->
        val points = mutableListOf<Point>()
        for (coordinate in coordinatesList) {
            if(coordinate.isObject()){
              val coordObject = value.getObject()
              points.add(Point.fromLngLat(coordObject.getProperty("longitude"), coordObject.getProperty("latitude")))
            }
        }
        setCoordinatesList(points)
      }
    }
  }
}
