

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
int pin         =  2; // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
int numPixels   = 4; // Popular NeoPixel ring size

// NeoPixel color format & data rate. See the strandtest example for
// information on possible values.
int pixelFormat = NEO_GRB + NEO_KHZ800;

Adafruit_NeoPixel *pixels;

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
 byte ll = 0;
 byte lr = 1;
 byte rr = 2;
 byte rl = 3;

int echoPin = 13;
int triggerPin = 12;
float duration;
double distance;

int reverseRight = 6;
int forwardRight = 9;
int reverseLeft = 10;
int forwardLeft = 11;


void setup() {
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(forwardLeft, OUTPUT);
  pinMode(forwardRight, OUTPUT);
  pinMode(reverseLeft, OUTPUT);
  pinMode(reverseRight, OUTPUT);
 
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif


  pixels = new Adafruit_NeoPixel(numPixels, pin, pixelFormat);

  pixels->begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  


}

void loop() {
  pixels->clear(); // Set all pixel colors to 'off'

   digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  if(distance < 35){
    
    pixels->setPixelColor(ll, pixels->Color(20,350, 0));
    pixels->setPixelColor(lr, pixels->Color(20,350, 0));
    pixels->setPixelColor(rr, pixels->Color(20,350, 0));
    pixels->setPixelColor(rl, pixels->Color(20,350, 0));
    pixels->show();  
    stopVehicle();
  } else{
    pixels->setPixelColor(rl, pixels->Color(100, 255, 0));
    pixels->setPixelColor(lr, pixels->Color(100,255, 0));
    pixels->setPixelColor(ll, pixels->Color(100,255, 0));
    pixels->setPixelColor(rr, pixels->Color(100,255, 0));
    pixels->show();
    moveForward();  

  }
}

void moveForward() {
  analogWrite(forwardLeft, 220);
  analogWrite(forwardRight, 220);
  analogWrite(reverseLeft, LOW);
  analogWrite(reverseRight, LOW);
}
void moveBackward() {
  analogWrite(forwardLeft, LOW);
  analogWrite(forwardRight, LOW);
  analogWrite(reverseLeft, 225);
  analogWrite(reverseRight, 220);
}
 
void turnRight() {
  analogWrite(forwardLeft, LOW);
  analogWrite(forwardRight, 190);
  analogWrite(reverseLeft, LOW);
  analogWrite(reverseRight, LOW);
}
 
void turnLeft() {
  analogWrite(forwardLeft, 190);
  analogWrite(forwardRight, LOW);
  analogWrite(reverseLeft, LOW);
  analogWrite(reverseRight, LOW);
}
 
void stopVehicle() {
  analogWrite(forwardLeft, LOW);
  analogWrite(forwardRight, LOW);
  analogWrite(reverseLeft, LOW);
  analogWrite(reverseRight, LOW);
}
