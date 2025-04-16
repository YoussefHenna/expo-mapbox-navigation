import { requireNativeViewManager } from "expo-modules-core";
import * as React from "react";

import {
  ExpoMapboxNavigationViewProps,
  ExpoMapboxNavigationViewRef,
} from "./ExpoMapboxNavigation.types";

const NativeView: React.ComponentType<ExpoMapboxNavigationViewProps> =
  requireNativeViewManager("ExpoMapboxNavigation");

export default React.forwardRef<
  ExpoMapboxNavigationViewRef,
  ExpoMapboxNavigationViewProps
>((props, ref) => {
  return <NativeView {...props} ref={ref} />;
});
