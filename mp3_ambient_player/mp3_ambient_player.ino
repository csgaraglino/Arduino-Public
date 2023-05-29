/***************************************************
  File: mp3_ambient_player
  (c) Chris Sgaraglino (https://www.sgaraglino.com)
  Uasge Rights: https://www.sgaraglino.com/usage-rights
  License: Creative Commons 3.0
 ***************************************************
 Description: Plays Ambient Music and/or Sound file
 Fritizing: mp3_ambient_player.jpg
 Board: UNO & Nano

 Notes: When adding an Arduino file, you have to delete 
 everything on the SD Card and copy everything from
 the source folder. File Date affect play order, not file name.

 The file nme needs to be 001.mp3 or 001.wav

 Date: May 27, 2023 
 Version: 1.0
 ****************************************************/


#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
 
int setVolume = 20; // Current Volumn 1 - 30
int clipPlaying = 1; // Set the file to play.

String version = "03/27/2023  v1.0"; // set the code date and version

SoftwareSerial mySoftwareSerial(10, 11); // Goes to DFP TX, Goes to DFP RX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  Serial.println();
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
    
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    delay(500);
    Serial.println(F("1.Please recheck the connection!"));
    delay(500);
    Serial.println(F("2.Please insert the SD card!"));
  }

  Serial.println(F("DFPlayer Mini online."));
  delay(500);
  Serial.println(String("Volume ") + String(setVolume)); 
  myDFPlayer.volume(setVolume);  //Set volume value. From 0 to 30
  delay(100);
//----Set different EQ----
  Serial.println(F("Setting EQ"));
  myDFPlayer.EQ(DFPLAYER_EQ_ROCK);
  delay(100);

  myDFPlayer.play(clipPlaying); // play the first file on the SD card
  Serial.println(String("Playing File ") + String(clipPlaying)); 

    }


void loop()
{
  // nothing to do here
}



// Problem notification for DFPlayer Mini
void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(String("Number ") + String(value));
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
  
}