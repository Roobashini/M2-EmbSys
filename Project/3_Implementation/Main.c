//flood monitoring..................................
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int trig1= A2;
const int eco1= 3;
const int level= A4;
const int flow= A3;
const int cm1= A1;
int duration1;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  dht.begin();
  pinMode(trig1,OUTPUT);
  pinMode(eco1,INPUT);
  pinMode(level,INPUT);
  pinMode(flow,INPUT);
  pinMode(cm1,INPUT);
  
  lcd.setCursor(1,0);lcd.print("FLOOD");
  lcd.setCursor(1,1);lcd.print("MONITORING IOT");
  delay(1000);

  lcd.clear();
  
}

void loop() 
{ 
 //to Read Temperature...........................................................
 
     int t = dht.readTemperature(); 
    lcd.setCursor(0,0);lcd.print("T:");
    if(t <= 9){lcd.print("0");lcd.print(t);}
    else if(t <= 99){lcd.print(t);}

//to Read Humidity................................................................
 
    int h = dht.readHumidity(); 
    lcd.setCursor(0,1);lcd.print("H:");
    if(h <= 9){lcd.print("0");lcd.print(h);}
    else if(h <= 99){lcd.print(h);}

//distance measurement.............................................................

  int c = analogRead(cm1);
  c = map(c,0,1023,0,150);
  lcd.setCursor(5,0);lcd.print("D:");
  if(c <= 9){lcd.print("00");lcd.print(c);}
  else if(c <= 99){lcd.print("0");lcd.print(c);}
  else if(c <= 999){lcd.print(c);}

//to read flow.....................................................................

  int f = analogRead(flow);
  f = map(f,0,1023,0,100);
  lcd.setCursor(11,0);lcd.print("F:");
  if(f <=9){lcd.print("00");lcd.print(f);}
  else if(f <= 99){lcd.print("0");lcd.print(f);}
  else if(f <= 999){lcd.print(f);}

//to read level.....................................................................

  int l = analogRead(level);
  l = map(l,0,1023,0,100);
  lcd.setCursor(5,1);lcd.print("L:");
  if(l <=9){lcd.print("00");lcd.print(l);}
  else if(l <= 99){lcd.print("0");lcd.print(l);}
  else if(l <= 999){lcd.print(l);}

    
}

