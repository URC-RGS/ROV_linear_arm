#include <Arduino.h>
#include <Servo.h>

unsigned long timing;
Servo pico;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pico.attach(9, 1000, 2000);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  pico.write(140);              // tell servo to go to position in variable 'pos'
  delay(12000);
  pico.write(40);              // tell servo to go to position in variable 'pos'
  delay(12000);
}
