#include<avr/interrupt.h>

bool hallU = digitalRead(2);
bool hallV = digitalRead(3);
bool hallW = digitalRead(4);

volatile int pulse;

float startTime; //time at latest interrupt
float lastTime; // time at last interrupt
float pulseTimeU; //time between two pulses of hall U
float pulseTimeV;
float pulseTimeW;
float meanPulseTime; //mean time of all interrupts

float ppm; //pulse per minute
float rpm; //revolutions per minute


void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(8, INPUT);

  attachInterrupt(0, HALL_U, CHANGE);
  attachInterrupt(1, HALL_V, CHANGE);
  
  Serial.begin(9600);
  cli();
  PCICR |= 0b00000010;
  PCMSK1 |= 0b00000001;
  sei();
  
}


  void loop() {

  Serial.println(rpm);
}


void HALL_U(){
  Serial.println("Hall U Function");
  /*
  startTime = millis(); //time at which interrupt occured
  hallU = digitalRead(2);
  pulse+=1;
  pulseTimeU=startTime - lastTime;
  meanPulseTime = ((pulseTimeU + pulseTimeV + pulseTimeW)/3.0);
  ppm = (1000.0/meanPulseTime)*60.0;
  rpm = ppm/60;
  lastTime = startTime;
  */
  }



void HALL_V(){

  Serial.println("Hall V Function");
  /*
  startTime = millis(); //time at which interrupt occured
  hallV = digitalRead(2);
  pulse+=1;
  pulseTimeV=startTime - lastTime;
  meanPulseTime = ((pulseTimeU + pulseTimeV + pulseTimeW)/3.0);
  ppm = (1000.0/meanPulseTime)*60.0;
  rpm = ppm/60;
  lastTime = startTime;
  */
}


ISR(PCINT1_vect){
  
  Serial.println("Hall W Function");
  /*
  startTime = millis(); //time at which interrupt occured
  hallW = digitalRead(2);
  pulse+=1;
  pulseTimeW=startTime - lastTime;
  meanPulseTime = ((pulseTimeU + pulseTimeV + pulseTimeW)/3.0);
  ppm = (1000.0/meanPulseTime)*60.0;
  rpm = ppm/60;
  lastTime = startTime;
  */
  }
