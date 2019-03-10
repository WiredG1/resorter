#include <AccelStepper.h>
#include <Servo.h>

int func = 0;
int OneKPin = A0;
int TenKPin = A1;
int HunKPin = A2;
int MilKPin = A3;
int URPin = A4;
float R1 = 1000.0;
float R2 = 10000.0;
float R3 = 100000.0;
float R4 = 1000000.0;
float UR = 0;
int servoPin = 5;
float RIn = 0;
float Buffer = 0;
bool catcherRunning = false;
bool wheelRunning = false;

Servo Grabber;

AccelStepper catcher(AccelStepper::FULL4WIRE, 9, 8, 6, 7);
AccelStepper wheel(AccelStepper::FULL4WIRE, 11, 10, 13, 12);

void setup() {
  
  Grabber.attach(servoPin);
  // put your setup code here, to run once:
  pinMode(OneKPin,OUTPUT);
  pinMode(TenKPin,OUTPUT);
  pinMode(HunKPin,OUTPUT);
  pinMode(MilKPin,OUTPUT);
  pinMode(URPin,INPUT);

  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("ready();");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String SerialIn = String(Serial.readStringUntil(';'));
    /*while(Serial.available()){
      Serial.read();
    }*/        
    SerialIn.trim();
    
    String args = SerialIn.substring(SerialIn.indexOf('(')+1,SerialIn.indexOf(')')+1);
    String fun = SerialIn.substring(0,SerialIn.indexOf('('));
    fun.toLowerCase();
    
    if(fun == "readresistance"){
      func = 1;
    } else if(fun == "catcherturn") {
      func = 2;
    } else if(fun == "transporterturn"){
      func = 3;
    } else if(fun == "ohmarmposition"){
      func = 4;
    } else {
      func = 5;
    }
    Serial.println(runFunc(func, args));
    

    
  }
  //Run stepper recursively
   while(catcherRunning){
      catcher.run();
      if(catcher.distanceToGo() == 0){
        Serial.println("catcherTurn();");
        catcherRunning = false;
      }
    }
    if(wheelRunning){
      wheel.run();
      if(wheel.distanceToGo() == 0){
        Serial.println("transporterTurn();");
        wheelRunning = false;
      }
    }
}

