
#ifndef ___0140803_invertedPendulem_robot__MotorControler__
#define ___0140803_invertedPendulem_robot__MotorControler__

//#include <iostream>
#include "Arduino.h"
#include "Streaming.h"

class MotorControler
{
public:
    MotorControler( int ,int, int);
    void motorCheckup();
    void motorControl(long value);
    
private:
    const int m_breakPin;
    const int m_directionPin;
    const int m_speedPin;
    int m_value;
    
};


#endif /* defined(___0140803_invertedPendulem_robot__MotorControler__) */

