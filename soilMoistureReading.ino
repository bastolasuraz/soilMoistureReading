// Only for testing purpose!!!
//Used for soil moisture sensor
float sensorValue = 0;
float per = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Moisture Sensor Value:");
sensorValue = analogRead(0);
Serial.println(sensorValue);
per = map(sensorValue, 785, 420, 0, 100);
Serial.println(per);
delay(500);
}
