import React from "react";
import { StyleSheet, View, Text } from "react-native";
import { MapboxNavigationView } from "expo-mapbox-navigation";
import Mapbox from "@rnmapbox/maps";
import * as Location from "expo-location";

Mapbox.setAccessToken("<TOKEN_HERE>");

export default function App() {
  React.useEffect(() => {
    (async () => {
      let { status } = await Location.requestForegroundPermissionsAsync();
      if (status === "granted") {
        setLocationAllowed(true);
      } else {
        setLocationAllowed(false);
      }
    })();
  }, []);

  const [locationAllowed, setLocationAllowed] = React.useState(false);
  return (
    <View style={styles.container}>
      {locationAllowed ? (
        <MapboxNavigationView
          style={{ flex: 1 }}
          coordinates={[
            { latitude: 30.044874, longitude: 31.46149 },
            { latitude: 30.068016, longitude: 31.42541 },
          ]}
        />
      ) : (
        <Text style={styles.text}>Location required for mapbox navigation</Text>
      )}
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: "center",
  },
  text: {
    alignSelf: "center",
  },
});
