import { ViewStyle, StyleProp } from "react-native/types";
import { Ref } from "react";

type ProgressEvent = {
  distanceRemaining: number;
  distanceTraveled: number;
  durationRemaining: number;
  fractionTraveled: number;
};

type Route = {
  distance: number;
  expectedTravelTime: number;
  legs: Array<{
    source?: { latitude: number; longitude: number };
    destination?: { latitude: number; longitude: number };
    steps: Array<{
      shape?: {
        coordinates: Array<{ latitude: number; longitude: number }>;
      };
    }>;
  }>;
};

type Routes = {
  mainRoute: Route;
  alternativeRoutes: Route[];
};

export type ExpoMapboxNavigationViewRef = {
  recenterMap: () => void;
};

export type ExpoMapboxNavigationViewProps = {
  ref?: Ref<ExpoMapboxNavigationViewRef>;
  coordinates: Array<{ latitude: number; longitude: number }>;
  waypointIndices?: number[];
  useRouteMatchingApi?: boolean;
  locale?: string;
  routeProfile?: string;
  routeExcludeList?: string[];
  mapStyle?: string;
  mute?: boolean;
  vehicleMaxHeight?: number;
  vehicleMaxWidth?: number;
  initialLocation?: { latitude: number; longitude: number; zoom?: number };
  onRouteProgressChanged?: (event: { nativeEvent: ProgressEvent }) => void;
  onCancelNavigation?: () => void;
  onWaypointArrival?: (event: {
    nativeEvent: ProgressEvent | undefined;
  }) => void;
  onFinalDestinationArrival?: () => void;
  onRouteChanged?: () => void;
  onUserOffRoute?: () => void;
  onRoutesLoaded?: (event: { nativeEvent: { routes: Routes } }) => void;
  style?: StyleProp<ViewStyle>;
};
