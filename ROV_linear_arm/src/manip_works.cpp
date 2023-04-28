#include "Servo.h"
#include "TroykaCurrent.h"

// создание объекта
ACS712 dataI(A0);

const int inp_pin=10; // пин, принимающий шим-сигнал
const int PinA1=11; // пин управления мотором
const int PinA2=12; // пин управления мотором
const int sens_pin = A0; // пин датчика тока
int zero; // откалиброванный ноль тока
byte speed=255; // скорость движения штока по восьмибитной шкале
bool caught=0; // флаг на остановку
unsigned long timing; // счетчик для задержек
const int stop_delta=180; // минимальная дельта для остановки
bool open_stopped=0; // флаг остановки на раскрытие
bool close_stopped=0; // флаг остановки на закрытие

void setup() {
  pinMode(inp_pin, INPUT);
  pinMode(PinA1, OUTPUT);
  pinMode(PinA2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // вывод показаний в последовательный порт
  int tok = 0;
  for(int i=1;i<10;i++){
    tok = tok + dataI.readCurrentAC()*1000;
  }
  tok = tok / 10;
  Serial.print("Current is ");
  Serial.print(tok);
  Serial.println(" mA");
  int impulse = pulseIn(inp_pin, HIGH); // считаем длительность полученного шим-сигнала
  Serial.println(impulse);
  if(impulse<1300 && 800<impulse){ // раскрытие
    if(tok<stop_delta){
      if(not open_stopped){
        analogWrite(PinA1, 0);
        analogWrite(PinA2, speed);
      }
      else{open_stopped=1;}
      open_stopped=0;
      if (millis() - timing > 10000){ // Вместо 10000 подставьте нужное вам значение паузы 
          timing = millis(); 
      }
    }
  }
  if(2400>impulse && impulse>1700){ // закрытие
    if(tok<stop_delta){
      if(not close_stopped){
        analogWrite(PinA1, speed);
        analogWrite(PinA2, 0);
      }
      else{close_stopped=1;}
      close_stopped=0;
      if (millis() - timing > 10000){ // Вместо 10000 подставьте нужное вам значение паузы 
          timing = millis(); 
      } 
    }
  }
}
