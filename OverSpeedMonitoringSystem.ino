#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int trigPin = 2;
const int echoPin = 3;
const int speedThreshold = 10;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 lcd.init();
 lcd.backlight();
 lcd.print("Speed Detector");
}
void loop() {
 long duration, distance;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(1);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(1);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = duration * 0.034 / 2;
 float speed = distance * 0.036;
 lcd.setCursor(0, 1);
 lcd.print("Speed: ");
 lcd.print(speed, 1);
 if (speed > speedThreshold) {
 lcd.print("Overspeed : ");
 lcd.print(speed, 1);
 } else {
 lcd.print(" km/h");
 lcd.print(speed, 1);
 }
 delay(1000);
