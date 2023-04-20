#include <sensorntc.h>

#include <Displays.h>

int estado;

void setup() {
  // put your setup code here, to run once:
displays.init(8,9,10,11,12,13);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
sensorntc.initntc(0);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available() > 0){
estado = Serial.read();
}
if (estado == '2') {
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
if (estado == '1') {

delay(500);
displays.cargarDato(sensorntc.leontc());
if(sensorntc.leontc()<20){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
if((sensorntc.leontc()>21)&&(sensorntc.leontc()<30)){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
}
if((sensorntc.leontc()>31)&&(sensorntc.leontc()<40)){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
}
if(sensorntc.leontc()>41){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
}
}
}
