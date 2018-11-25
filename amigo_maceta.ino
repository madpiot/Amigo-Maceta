/**************************************************************
 * TARGET       : AMIGO MACETA
 * PROGRAMMER   : Madhu Parvathaneni
 * HARDWARE     : Venkatesh
 * TESTER       : Rabbani Basha
 * ORGANIZATION : ORL Industries
 * COPYRIGHT (C): Orange Research Labs
 * DATE         : 24th November 2018
 ***************************************************************/

#include "LedControl.h"
#include "binary.h"

LedControl lc=LedControl(12,11,10,1); // DIN, CLK, CS

// delay time between faces
unsigned long delaytime=1000;

// happy face (http://dotmatrixtool.com/)
byte hf[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
// neutral face
byte nf[8]={B00111100, B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};
// sad face
byte sf[8]= {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};

void setup() 
{
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);  
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  Serial.println("WELCOME TO AMIGO MACETA TEST");
  delay(1000);
}

void sadFace()
{
  Serial.println("Displaying Sad Face");
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  lc.setRow(0,0,sf[0]);
  lc.setRow(0,1,sf[1]);
  lc.setRow(0,2,sf[2]);
  lc.setRow(0,3,sf[3]);
  lc.setRow(0,4,sf[4]);
  lc.setRow(0,5,sf[5]);
  lc.setRow(0,6,sf[6]);
  lc.setRow(0,7,sf[7]);
  delay(delaytime);
}

void happyFace()
{
  Serial.println("Displaying Happy Face");
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  lc.setRow(0,0,hf[0]);
  lc.setRow(0,1,hf[1]);
  lc.setRow(0,2,hf[2]);
  lc.setRow(0,3,hf[3]);
  lc.setRow(0,4,hf[4]);
  lc.setRow(0,5,hf[5]);
  lc.setRow(0,6,hf[6]);
  lc.setRow(0,7,hf[7]);
  delay(delaytime);
}

void neutralFace()
{
  Serial.println("Displaying Neutral Face");
  lc.setRow(0,0,nf[0]);
  lc.setRow(0,1,nf[1]);
  lc.setRow(0,2,nf[2]);
  lc.setRow(0,3,nf[3]);
  lc.setRow(0,4,nf[4]);
  lc.setRow(0,5,nf[5]);
  lc.setRow(0,6,nf[6]);
  lc.setRow(0,7,nf[7]);
  delay(delaytime);
}

void loop()
{
  if(digitalRead(2)==1)
    sadFace();
  else
    happyFace();
}
