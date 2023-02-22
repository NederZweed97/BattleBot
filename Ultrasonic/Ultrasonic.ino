// took example code from https://srituhobby.com/ultrasonic-sensor-with-arduino-nano-how-does-work-ultrasonic-sensor/
void setup() {
  pinMode(12, OUTPUT);//define arduino pin
  pinMode(13, INPUT);//define arduino pin
  Serial.begin(9600);//enable serial monitor

}
void loop() {
  //pulse output
  digitalWrite(12, LOW);
  delayMicroseconds(4);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  
  long t = pulseIn(13, HIGH);//input pulse and save it veriable
  
  long inches = t / 74 / 2; //time convert distance
  long cm = t / 29 / 2; //time convert distance
  String inch = " inches t";
  String CM = " cm";

  Serial.print(inches +inch);//print serial monitor inches
  Serial.println(cm +CM);//print serial monitor cm
  Serial.println();//print space
  delay(100);//delay
}
