import React from "react";
import { StyleSheet, View } from "react-native";
import { MapboxNavigationView } from "expo-mapbox-navigation";

export default function App() {
  return (
    <View style={styles.container}>
      <MapboxNavigationView
        coordinatesList={[
          { latitude: 30.044874, longitude: 31.461499 },
          { latitude: 30.068016, longitude: 31.425419 },
        ]}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
});
