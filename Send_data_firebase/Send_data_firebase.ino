#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
int test1;

//................SSID DAN PASS PADA WIFI................//
const char* ssid = "*********";
const char* pass = "*********";

//................HOST DAN TOKEN PADA FIREBASE................//
#define FIREBASE_HOST "*********"
#define FIREBASE_TOKEN "*********"

FirebaseData TestData;

void setup() {
  Serial.begin(115200);
  Serial.println();
  WiFi.begin(ssid, pass);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.println("Tunggu.");
  }
  Serial.println();
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_TOKEN);
  Firebase.reconnectWiFi(true);
}
void loop() {
  //Pada test pengiriman ini menggunakan Milis//
  //Bisa juga untuk mengirim penangkapan sensor data seperti suhu//
  test1 = millis();
  Serial.print("Data yang dikirim = ");
  Serial.println(test1);
  Firebase.setFloat(TestData, "/data/send", test1); //Path pada database Firebase contoh /data/send
}
