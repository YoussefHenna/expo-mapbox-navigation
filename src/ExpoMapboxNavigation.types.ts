import { ViewStyle, StyleProp } from "react-native/types";

export type ExpoMapboxNavigationViewProps = {
  coordinates: Array<{ latitude: number; longitude: number }>;
  style?: StyleProp<ViewStyle>;
};
