/***********************************************************
File name: 25_ledMatrix.ino
Description: you can see a rolling “Uctronics” should be displayed
             on the dot matrix display.
Website: www.uctronics.com
E-mail: sales@uctronics.com 
Author: Lee
Date: 2017/01/16 
***********************************************************/

const int latchPin = 12; //Pin connected to ST_CP of 74HC595
const int clockPin = 8;//Pin connected to SH_CP of 74HC595  
const int dataPin = 11; //Pin connected to DS of 74HC595 
//Column scanning
int data[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//Null
               {0x40,0x7C,0x44,0x04,0x04,0x44,0x7C,0x40},/*"U",0*/
			  {0x00,0x0C,0x12,0x12,0x12,0x12,0x12,0x00},/*"c",1*/
			  {0x00,0x10,0x10,0x3E,0x12,0x12,0x00,0x00},/*"t",2*/
			  {0x12,0x12,0x1E,0x0A,0x12,0x10,0x10,0x00},/*"r",3*/
			  {0x00,0x0C,0x12,0x12,0x12,0x12,0x0C,0x00},/*"o",4*/
			  {0x12,0x1E,0x12,0x10,0x10,0x12,0x1E,0x02},/*"n",5*/
			  {0x00,0x12,0x32,0x3E,0x02,0x02,0x00,0x00},/*"i",6*/
			  {0x00,0x0C,0x12,0x12,0x12,0x12,0x12,0x00},/*"c",7*/
			  {0x00,0x1A,0x1A,0x16,0x16,0x16,0x16,0x00},/*"s",8*/
              0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00  //Null
              };
              
//Line scan            
unsigned char  tab[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};  

void setup ()
{
  //set pins to output
  pinMode(latchPin,OUTPUT);//Set digital 12 port mode, the OUTPUT for the output
  pinMode(clockPin,OUTPUT);//Set digital 8 port mode, the OUTPUT for the output
  pinMode(dataPin,OUTPUT); //Set digital 11 port mode, the OUTPUT for the output
}

void loop()
{
    for(int n = 0; n < 56; n++) //Send column scanning cycle data
    {
        for(int t=0;t<100;t++)  //Control data scrolling speed
        {
            for(int num=n; num < 8+n; num++)//8 columns of data sent to a dot matrix
            {                       
                shiftOut(dataPin,clockPin,MSBFIRST,data[num]); //Send column data to a dot matrix
                shiftOut(dataPin,clockPin,MSBFIRST,tab[num-n]);//Send line data to a dot matrix
                //The rising edge of the data shift
                digitalWrite(latchPin,HIGH); //Output control latch HIGH  
                digitalWrite(latchPin,LOW);  //Output control latch LOW
            }
        }
    }
}
