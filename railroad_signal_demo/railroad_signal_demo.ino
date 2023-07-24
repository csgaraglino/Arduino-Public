/***************************************************
  File: railroad_signal_demo
  (c) Chris Sgaraglino https://www.sgaraglino.com
  Uasge Rights: https://www.sgaraglino.com/usage-rights
  License: Creative Commons 3.0
 ***************************************************
  If you would like to buy me a beer for my hard work 
  and help keep these projects free, PayPal me a few
  bucks at: chris@sgaraglino.com 
 ***************************************************
  Description: Designed to run a real size 3-light sigbal
  Fritizing: Yes
  Board: UNO & Nano

  Date: July 23, 2023 
  Version: 1.0
 ****************************************************/


#define LEDG 02
#define LEDY 03
#define LEDR 04
int pauseNext;
int randNumber;
void setup()
{
  Serial.begin(9600);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDR, OUTPUT);

}

void loop() {

digitalWrite(LEDG, HIGH);
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDR, LOW);
  randNumber = random(1, 10);
  pauseNext = randNumber*10000;
  Serial.println(String("Green ") + String(pauseNext) +String("sec"));
  delay(pauseNext);

  digitalWrite(LEDG, LOW);
  digitalWrite(LEDY, HIGH);
  digitalWrite(LEDR, LOW);
  randNumber = random(1, 10);
  pauseNext = randNumber*1000;
  Serial.println(String("Yellow ") + String(pauseNext) +String("sec"));
  delay(pauseNext);
  
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDR, HIGH);
  randNumber = random(1, 10);
  pauseNext = randNumber*1000;
  Serial.println(String("Red ") + String(pauseNext) +String("sec"));
  delay(pauseNext);
  
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDY, HIGH);
  digitalWrite(LEDR, LOW);
  randNumber = random(1, 10);
  pauseNext = randNumber*1000;
  Serial.println(String("Yellow ") + String(pauseNext) +String("sec"));
  delay(pauseNext);

}