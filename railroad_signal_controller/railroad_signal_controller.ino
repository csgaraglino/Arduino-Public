/***************************************************
  File: railroad_signal_controller
  (c) Chris Sgaraglino https://www.sgaraglino.com
  Usage Rights: https://www.sgaraglino.com/usage-rights
  License: Creative Commons 3.0
 ***************************************************
  If you would like to buy me a beer for my hard work 
  and help keep these projects free, PayPal me a few
  bucks at: chris@sgaraglino.com 
 ***************************************************
  Description: Designed to run a real size 3-light signal
  Fritizing: Yes
  Board: UNO & Nano

  Note: I am using a noise value from A0 to seed the 
  randomSeed() function to produce a different sequence 
  of random numbers, every time random() runs.
  Read this blog post I wrote to know why:
  https://www.wcmrr.com/railroad-signal-controller

 ****************************************************/

String version = "07/24/2023  v1.1.1"; // set the code date and version

#define LEDG 02
#define LEDY 03
#define LEDR 04
int randVal1 = 20; //Random Value Start
int randVal2 = 60; //Random Value End

void setup()
{
  Serial.begin(9600);
  Serial.println(String(" "));
  Serial.println(String("Railroad Signal Controller"));
  Serial.println(String("Widow Creek Electronics"));
  Serial.println(String("www.widowcreekelectronics.com"));
  Serial.println(String(version));

  pinMode(LEDG, OUTPUT);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDR, OUTPUT);
  randomSeed(analogRead(A0)); // grab a floating number form the analog noise  

}

void loop() {

  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDR, LOW);
  // Serial.println(String("Green ") + String((random(randVal1, randVal2))*1000) + String(" ms"));
  delay((random(randVal1, randVal2))*1000);

  digitalWrite(LEDG, LOW);
  digitalWrite(LEDY, HIGH);
  digitalWrite(LEDR, LOW);
  // Serial.println(String("Yellow ") + String((random(randVal1, randVal2))*1000) + String(" ms"));
  delay((random(randVal1, randVal2))*1000);
  
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDR, HIGH);
  // Serial.println(String("Red ") + String((random(randVal1, randVal2))*1000) + String(" ms"));
  delay((random(randVal1, randVal2))*1000);
  
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDY, HIGH);
  digitalWrite(LEDR, LOW);
  // Serial.println(String("Yellow ") + String((random(randVal1, randVal2))*1000) + String(" ms"));
  delay((random(randVal1, randVal2))*1000);

}