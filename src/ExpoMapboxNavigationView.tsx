import { requireNativeViewManager } from "expo-modules-core";
import * as React from "react";

import { ExpoMapboxNavigationViewProps } from "./ExpoMapboxNavigation.types";

type Props = ExpoMapboxNavigationViewProps;

const NativeView: React.ComponentType<ExpoMapboxNavigationViewProps> =
  requireNativeViewManager("ExpoMapboxNavigation");

export default function ExpoMapboxNavigationView(
  props: ExpoMapboxNavigationViewProps
) {
  return <NativeView {...props} />;
}
