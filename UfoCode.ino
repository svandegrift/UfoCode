#include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMPIXELS      8
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
float loopSpeed;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 500;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("Start");
  strip.begin();
}

///////////////////////////////////////////////////////////////////////////////////////
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  distance = map(distance, 0, 70, 5, 25);
  loopSpeed = distance * 0.001;
  Serial.println(distance);
  float s = .5;
  float t = millis() * loopSpeed;
  for (int i = 0; i < strip.numPixels(); i++) {
    float rv = (sin(i * s + t + 45) + 1) / 2;
    float gv = (sin(i * s + t + 43) + 1) / 2;
    float bv = (sin(i * s + t + 40) + 1) / 2;
    byte r = rv * 210;
    byte g = gv * 200;
    byte b = bv * 25;
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
  }
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
