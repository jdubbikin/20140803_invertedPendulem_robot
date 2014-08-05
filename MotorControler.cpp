//
//  MotorControler.cpp
//  20140803_invertedPendulem_robot
//
//  Created by James Wood 柯杰。 on 8/4/14.
//  Copyright (c) 2014 James Wood 柯杰。. All rights reserved.
//



#include "MotorControler.h"

MotorControler::MotorControler(int directionPin, int speedPin, int brakePin )
:m_breakPin(brakePin), m_speedPin(speedPin), m_directionPin(directionPin)
{
    pinMode(m_directionPin, OUTPUT);  // This sets the direction pin as an output.
    pinMode(m_speedPin, OUTPUT);  // This sets the brake pin as an output.
    pinMode(m_breakPin, OUTPUT);  // This sets the brake pin as an output.
}

void MotorControler::motorCheckup()
{
    Serial << "Motor: " << " breakPin = " << m_breakPin << ", speedPin = " << m_speedPin << ", directionPin = " << m_directionPin << endl;
}

void MotorControler::motorControl(long value)
{
    
    if (value > 255) {value = 255;}
    if (value < -255) {value = -255;}
    
    m_value = value;
    
    if(m_value < 0)
    {
        digitalWrite( m_breakPin, LOW);
        digitalWrite( m_directionPin, HIGH);
        analogWrite( m_speedPin, abs(m_value));
        
#ifdef DEBUG_MOTORS
        Serial << m_value << "\t" << digitalRead(m_breakPin) << "\t" << digitalRead(m_directionPin) << endl;
#endif
        
    }
    
    if(m_value > 0)
    {
        digitalWrite( m_breakPin, LOW);
        digitalWrite( m_directionPin, LOW);
        analogWrite( m_speedPin, abs(value));
        
#ifdef DEBUG_MOTORS
        Serial << m_value << "\t" << digitalRead(m_breakPin) << "\t" << digitalRead(m_directionPin) << endl;
#endif
        
    }
    if(m_value == 0)
    {
        digitalWrite( m_breakPin, HIGH);
        
#ifdef DEBUG_MOTORS
        Serial << m_value << "\t" << digitalRead(m_breakPin) << "\t" << digitalRead(m_directionPin) << endl;
#endif
        
    }
    
}
