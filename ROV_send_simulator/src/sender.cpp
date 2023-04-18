#include <Arduino.h>
#include <Servo.h>

unsigned long timing;
Servo pico;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pico.attach(10, 1000, 2000);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    pico.write(pos);              // tell servo to go to position in variable 'pos'
    if (millis() - timing > 10000){ // Вместо 10000 подставьте нужное вам значение паузы 
        timing = millis(); 
    }                   // waits 15 ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    pico.write(pos);              // tell servo to go to position in variable 'pos'
    if (millis() - timing > 10000){ // Вместо 10000 подставьте нужное вам значение паузы 
        timing = millis(); 
    }        
  }
}
