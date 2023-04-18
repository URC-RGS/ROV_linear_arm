#include <Arduino.h>
#include <Servo.h>

const int inp_pin=10;
const int PinA1=5;
const int PinA2=6;
byte speed=255;


void setup() {
  pinMode(inp_pin, INPUT);
  pinMode(PinA1, OUTPUT);
  pinMode(PinA2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(pulseIn(inp_pin, HIGH));
  if(pulseIn(inp_pin, HIGH)<1300 && 800<pulseIn(inp_pin, HIGH)){
    analogWrite(PinA1, 0);
    analogWrite(PinA2, speed);
    delay(5000);
  }
  if(2400>pulseIn(inp_pin, HIGH) && pulseIn(inp_pin, HIGH)>1700){
    analogWrite(PinA1, speed);
    analogWrite(PinA2, 0);
    delay(5000);
  }
}
