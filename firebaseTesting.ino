#include "Firebase_Arduino_WiFiNINA.h"

//setting data object in global scope
FirebaseData firebaseData;
#define HOST ""
#define AUTH ""
#define W_SSID ""
#define W_PASS ""

String DEVICEID = "01";
String PATH = "";

void setup() {
  Serial.begin(9600);
  delay(100);
  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED)
  {
    status = WiFi.begin(W_SSID, W_PASS);
    Serial.print("......");
    delay(300);
  }
  Serial.println(WiFi.localIP());
  Firebase.begin(HOST, AUTH, W_SSID, W_PASS);
  Firebase.reconnectWiFi(true);  
}

void loop() {  
  int soilMoisture = analogRead(0);
  String firebasePath = PATH + "/" + DEVICEID;
  if (Firebase.pushInt(firebaseData, firebasePath, soilMoisture)){
    Serial.println("Data Inserted"); 
  }
  else{
    Serial.println("REASON: " + firebaseData.errorReason());  
  }
  delay(5000);
}
