import MapboxNavigationView from "./ExpoMapboxNavigationView";
import MapboxNavigationModule from "./ExpoMapboxNavigationModule";
import { ExpoMapboxNavigationViewProps } from "./ExpoMapboxNavigation.types";

function setAccessToken(token: string) {
  MapboxNavigationModule.setAccessToken(token);
}

export {
  MapboxNavigationView,
  ExpoMapboxNavigationViewProps as MapboxNavigationViewProps,
  setAccessToken,
};
