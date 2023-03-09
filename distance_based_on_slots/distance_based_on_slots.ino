unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 10000;
int enB = 3;
int in3 = 11;
int in4 = 10;
int sensor = 7;
int steps=0;
float steps_old=0;
float temp=0;
float rps=0;

void setup() {
    Serial.begin(9600);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(sensor,INPUT_PULLUP);
    startMillis = millis();
    
  Serial.println(" STEPS - 0");
  Serial.println(" RPS   - 0.00");
}

void loop() {

//    currentMillis = millis();
//    if(currentMillis - startMillis <= period){ 
//          analogWrite(enB, 100);
//          digitalWrite(in3, HIGH);
//          digitalWrite(in4, LOW);
//          digitalRead(sensor);
//          steps=steps+1;
//          Serial.println(steps);  
//      if(steps == 1750){
//          digitalWrite(in3, LOW);
//          digitalWrite(in4, LOW);
//      }     
//    } else{
//
//          digitalWrite(in3, LOW);
//          digitalWrite(in4, LOW);
//       }
//
 
if(steps == 950){
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
} else{
           analogWrite(enB, 100);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
          digitalRead(sensor);
          steps=steps+1;
          Serial.println(steps); 
}


}
