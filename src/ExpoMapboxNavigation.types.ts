import { ViewStyle, StyleProp } from "react-native/types";

export type ExpoMapboxNavigationViewProps = {
  coordinates: Array<{ latitude: number; longitude: number }>;
  routeOptions?: {
    maxHeight?: number;
    maxWidth?: number;
  }; 
  waypointIndices?: number[];
  useRouteMatchingApi?: boolean;
  locale?: string;
  style?: StyleProp<ViewStyle>;
};
