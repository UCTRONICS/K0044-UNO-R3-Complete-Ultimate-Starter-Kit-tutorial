/***********************************************************
File name: 30_PIR_movement.ino
Description: The LED will be turned on when the motion has been detected.
Website: www.uctronics.com
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/01/16 
***********************************************************/

int ledpin=11;           //Set the digital 11 to LED
int PIRpin=5;           //Set the digital 5 to PIR
void setup() {
  // put your setup code here, to run once:
  pinMode( ledpin,OUTPUT);     //initialize the  led pin as output 
  pinMode( PIRpin,INPUT);     //initialize the  PIR pin as input
}

void loop() {
  
  if(digitalRead(PIRpin)==LOW)//Detecting whether the body movement information
  {
    digitalWrite(ledpin,LOW);//LED OFF
  }else
  {
    digitalWrite(ledpin,HIGH);//LED ON
  }
}
