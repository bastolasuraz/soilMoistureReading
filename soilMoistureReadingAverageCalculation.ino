// Only for testing purpose!!!
//Used for soil moisture sensor
float value = 0;
float average =0;
String per;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Moisture Sensor Value:");
for (int i=1; i < 3; i++){ 
  average = average + analogRead(0);  
  }
average = average / 3; 
Serial.println(average);
per = map(average, 785, 420, 0, 100);
Serial.print("Moisture Sensor Value in percentage:   ");
Serial.println(per);
delay(500);
}
