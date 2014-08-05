/// 
/// @mainpage	20140803_invertedPendulem_robot 
///
/// @details	EmbedXcode+ inverted pedulum project.
/// @n 		
/// @n 
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		James Wood 柯杰。
/// @author		James Wood 柯杰。
/// @date		8/3/14 11:19 AM
/// @version	0.1
/// 
/// @copyright	(c) James Wood 柯杰。, 2014
/// @copyright	GNU General Public License
///
/// @see		ReadMe.txt for references
///


///
/// @file		_0140803_invertedPendulem_robot.ino
/// @brief		Main sketch
///
/// @details	0.1
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		James Wood 柯杰。
/// @author		James Wood 柯杰。
/// @date		8/3/14 11:19 AM
/// @version	0.1
/// 
/// @copyright	(c) James Wood 柯杰。, 2014
/// @copyright	GNU General Public License
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430 G2 and F5529, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif

#include "Streaming.h"
#include "MotorControler.h"

#define ENCODER1A 30
#define ENCODER1B 31
#define ENCODER2A 32
#define ENCODER2B 33



// Include application, user and local libraries


// Prototypes

void encoderSetup();
void doEncoder1A();
void doEncoder1B();
void doEncoder2A();
void doEncoder2B();

// Define variables and constants

int encoder1Pos = 0;
int encoder2Pos = 0;

MotorControler motorA( 12, 3, 9 );
MotorControler motorB( 13, 11, 8 );

// Add setup code 
void setup() 
{
    Serial.begin( 115200 );
    encoderSetup();
}

// Add loop code 
void loop() 
{

}

void encoderSetup()
{
    pinMode( ENCODER1A, INPUT );
    pinMode( ENCODER1B, INPUT );
    pinMode( ENCODER2A, INPUT );
    pinMode( ENCODER2B, INPUT );
    
    attachInterrupt( ENCODER1A, doEncoder1A, CHANGE );
    attachInterrupt( ENCODER1B, doEncoder1B, CHANGE );
    attachInterrupt( ENCODER2A, doEncoder2A, CHANGE );
    attachInterrupt( ENCODER2B, doEncoder2B, CHANGE );
    
    encoder1Pos = 0;
    encoder2Pos = 0;
}

void doEncoder1A()
{
  // Look for low to high on encoder 1A
  if(digitalRead(ENCODER1A) == HIGH)
  {
    if(digitalRead(ENCODER1B) == LOW)
    {
      encoder1Pos += 1;
    }
    else
    {
      encoder1Pos -= 1;
    }
  }
  else
  {
    if(digitalRead(ENCODER1B) == HIGH)
    {
      encoder1Pos += 1;
    }
    else
    {
      encoder1Pos -= 1;
    }
  }

    Serial << digitalRead(30) << "\t" <<  digitalRead(31) << "\t" <<  digitalRead(32) << "\t" <<  digitalRead(33) << "\t" ;
    Serial << encoder1Pos << "\t" << encoder2Pos << endl;
}


void doEncoder1B()
{
  // Look for low to high on encoder 1A
  if(digitalRead(ENCODER1B) == HIGH)
  {
    if(digitalRead(ENCODER1A) == HIGH)
    {
      encoder1Pos += 1;
    }
    else
    {
      encoder1Pos -= 1;
    }
  }
  else
  {
    if(digitalRead(ENCODER1A) == LOW)
    {
      encoder1Pos += 1;
    }
    else
    {
      encoder1Pos -= 1;
    }
  }
  
    Serial << digitalRead(30) << "\t" <<  digitalRead(31) << "\t" <<  digitalRead(32) << "\t" <<  digitalRead(33) << "\t" ;
    Serial << encoder1Pos << "\t" << encoder2Pos << endl;
}


void doEncoder2A()
{
  // Look for low to high on encoder 1A
  if(digitalRead(ENCODER2A) == HIGH)
  {
    if(digitalRead(ENCODER2B) == LOW)
    {
      encoder2Pos -= 1;
    }
    else
    {
      encoder2Pos += 1;
    }
  }
  else
  {
    if(digitalRead(ENCODER2B) == HIGH)
    {
      encoder2Pos -= 1;
    }
    else
    {
      encoder2Pos += 1;
    }
  }
  
    Serial << digitalRead(30) << "\t" <<  digitalRead(31) << "\t" <<  digitalRead(32) << "\t" <<  digitalRead(33) << "\t" ;
    Serial << encoder1Pos << "\t" << encoder2Pos << endl;

}


void doEncoder2B()
{
  // Look for low to high on encoder 1A
  if(digitalRead(ENCODER2B) == HIGH)
  {
    if(digitalRead(ENCODER2A) == HIGH)
    {
      encoder2Pos -= 1;
    }
    else
    {
      encoder2Pos += 1;
    }
  }
  else
  {
    if(digitalRead(ENCODER2A) == LOW)
    {
      encoder2Pos -= 1;
    }
    else
    {
      encoder2Pos += 1;
    }
  }
  
    Serial << digitalRead(30) << "\t" <<  digitalRead(31) << "\t" <<  digitalRead(32) << "\t" <<  digitalRead(33) << "\t" ;
    Serial << encoder1Pos << "\t" << encoder2Pos << endl;

}
