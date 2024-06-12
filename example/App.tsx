import React from "react";
import { StyleSheet, View, Text } from "react-native";
import { MapboxNavigationView } from "expo-mapbox-navigation";
import Mapbox from "@rnmapbox/maps";

Mapbox.setAccessToken("<TOKEN_HERE>");

export default function App() {
  return (
    <View style={styles.container}>
      <MapboxNavigationView
        style={{ flex: 1 }}
        coordinates={[
          { latitude: 30.044874, longitude: 31.46149 },
          { latitude: 30.068016, longitude: 31.42541 },
        ]}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "red",
  },
});
