/***********************************************************
File name: 04_relay.ino
Description:When the relay sucks, the LED will light up; when 
            the relay breaks, the LED will go out.
Website: www.uctronics.com
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/01/16 
***********************************************************/
const int relayPin = 8; //the base of the transistor attach to

void setup()
{
  pinMode(relayPin, OUTPUT); //initialize the relayPin as an output
}

void loop()
{
  digitalWrite(relayPin, HIGH); //drive relay closure conduction
  delay(1000); //wait for a second

  digitalWrite(relayPin, LOW); //drive the relay is closed off
  delay(1000); //wait for a second
}

