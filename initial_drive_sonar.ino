
int a1 = 11; //links (150, vooruit)
int a2 = 10; //rechts (150, vooruit)
int b1 = 9; // rechts (achteruit)
int b2 = 3; // Links (achteruit)
int p1 = 6;
int p2 = 5;
int trigPin = 7;
int echoPin = 4;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:

  long duration, distance; 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); // 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);// 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.write(distance);

      digitalWrite(a1, 195);
      digitalWrite(a2, LOW);
      digitalWrite(b1, 200);
      digitalWrite(b2, LOW);

      



}
