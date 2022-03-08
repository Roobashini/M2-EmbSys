#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); // gsm module connected here
 
#define trigpin 4 // digital pin 4 
#define echopin 2 // digital pin 2
 
String textForSMS;
 
// flags definitions to stop the repetitions of sms
int flag1 = 0; // 
int flag2 = 0; // 
int flag3 = 0; // 
int flag4 = 0; //
 
void setup()
{
Serial.begin(9600);
SIM900.begin(19200);
SIM900power();
  delay(5000);  // give time to log on to network. 
  Serial.println(" logging time completed!");
  randomSeed(analogRead(0));
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
 
}
 
void SIM900power()
// software equivalent of pressing the GSM shield "power" button
{
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(7000);
}
 
void sendSMS(String message)
{
  SIM900.print("AT+CMGF=1\r");                     // AT command to send SMS message
  delay(100);
  SIM900.println("AT + CMGS = \"+923049844408\"");  // recipient's mobile number, in international format
  delay(100);
  SIM900.println(message);                         // message to send
  delay(100);
  SIM900.println((char)26);                        // End AT command with a ^Z, ASCII code 26
  delay(100); 
  SIM900.println();
  delay(5000);                                     // give module time to send SMS
 // SIM900power();                                   // turn off module
}
 
 
void loop()
{
 int duration, distance; 
 digitalWrite(trigpin, HIGH);
delayMicroseconds(1000);  
digitalWrite(trigpin, LOW);
 
duration = pulseIn(echopin,HIGH);
distance = ( duration / 2) / 29.1;
 
 
Serial.println(distance);
delay(100);
 
 if ( (distance > 0 ) && (distance <10 ) && ( flag1 == 0))
 {
   Serial.println (" critical2 ");
   textForSMS = "critical situation 2  ";
 
 
  sendSMS(textForSMS);
  Serial.println("message sent.");
  delay(10000);
   flag1 = 1;
delay(1000);
 }
  if ( (distance > 10 ) && (distance <20 ) && ( flag1 == 1))
 {
   Serial.println (" critical1 ");
   textForSMS = "critical situation 1  ";
 
 
  sendSMS(textForSMS);
  Serial.println("message sent.");
  delay(10000);
   flag1 = 0;
delay(1000);
 }
 
 
 
  if ( (distance > 20 ) && (distance <30 ) && ( flag2 == 0))
 {
   Serial.println ("level high2 ");
   textForSMS = "level high2  ";
 
 
  sendSMS(textForSMS);
  Serial.println("message sent.");
  delay(10000);
   flag2 = 1;
delay(1000);
 }
   if ( (distance > 30 ) && (distance <40 )&& (flag2 == 1))
 {
   Serial.println ("level high1 ");
   textForSMS = "level high1  ";
 
 
  sendSMS(textForSMS);
  Serial.println("message sent.");
  delay(10000);
   flag2 = 0;
delay(1000);
 }
 
   if ( (distance > 40 ) && (distance <50 ) && ( flag3 == 0))
 {
   Serial.println ("level medium 2 ");
   textForSMS = "medium level 2  ";
 
 
  sendSMS(textForSMS);
  Serial.println("message sent.");
  delay(10000);
   flag3 = 1;
delay(1000);
 }
   if ( (distance > 50 ) && (distance <60 )&& (flag3 == 1))
 {
   Serial.println ("medium level 1 ");
   textForSMS = "medium level 1  ";
 
 
  sendSMS(textForSMS);
  Serial.println("message sent.");
  delay(10000);
   flag3 = 0;
delay(1000);
 }
 
   if ( (distance > 60 ) && (distance <70 ) && ( flag4 == 0))
 {
   Serial.println ("Normal level ");
   textForSMS = "normal level  ";
 
 
  sendSMS(textForSMS);
  Serial.println("message sent.");
  delay(10000);
   flag4 = 1;
delay(1000);
 }
   if ( (distance > 70 ) && (distance <100 )&& (flag4 == 1))
 {
   Serial.println ("lower ");
   textForSMS = "lower  ";
 
 
  sendSMS(textForSMS);
  Serial.println("message sent.");
  delay(10000);
   flag4 = 0;
delay(1000);
 } 
 
  
//Serial.print(distance);
//Serial.print("Centimeters\n");
//delay(2000);
 
}


 


