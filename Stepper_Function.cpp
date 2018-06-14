/**********************************************************************************************
 * Arduino Stepper_Function Library - Version 1.0
 * by William Bailes <williambailes@gmail.com> http://tinkersprojects.com/
 *
 * This Library is licensed under a GPLv3 License
 **********************************************************************************************/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Stepper_Function.h"



/******************* SETUP *******************/

Stepper_Function::Stepper_Function(byte enablePin,byte directionPin,byte stepPin,Position *GetPosition,double (*CallBack)(Position StepPosition));

{
    Enable_Pin = enablePin;
    Direction_Pin = directionPin;
    Step_Pin = stepPin;
    pinMode(Enable_Pin, OUTPUT);
    pinMode(Direction_Pin, OUTPUT);
    pinMode(Step_Pin, OUTPUT);
    
    &FuturePosition = GetPosition;
    KinematicsCallBack = callback;
}



/******************* SET *******************/

void Stepper_Function::setSpeed(unsigned long speedValue)
{
    Speed = speedValue;
}

void Stepper_Function::setAcceleration(unsigned double accelerationValue)
{
    Acceleration = accelerationValue;
}



/******************* GET *******************/

unsigned long Stepper_Function::getSpeed()
{
 return speedValue
}

unsigned long Stepper_Function::getCurrentSpeed()
{
 return CurrentSpeed
}

double Stepper_Function::getAcceleration()
{
 return Acceleration;
}

        
/******************* CHECKING *******************/

boolean Stepper_Function::hasFinished()
{

}



/******************* COMMANDS *******************/

void Stepper_Function::run()
{
    KinematicsCallBack(*FuturePosition);
}

void Stepper_Function::runOff()
{
    
}

void Stepper_Function::stop()
{
    
}

void Stepper_Function::delay(unsigned long delayValue)
{
    
}

