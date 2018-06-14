
#ifndef Stepper_Function_h
#define Stepper_Function_h

#include "position.h"

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <wiring.h>
#endif


class Stepper_Function
{
    public:
        // SETUP 
        Stepper_Function(byte enablePin,byte directionPin,byte stepPin,Position *GetPosition,double (*CallBack)(Position SetPosition));

        // SET 
        void goto(long x,long y,long z);
        void setSpeed(unsigned long speedValue);
        void setAcceleration(unsigned double accelerationValue);
        
        //GET
        unsigned long getSpeed();
        unsigned long getCurrentSpeed();
        unsigned double getAcceleration();

        // CHECKING 
        boolean hasFinished();
        
        // COMMANDS 
        void run();
        void runOff();
        void stop();
        void delay(unsigned long delayValue);
        
    private:

        Position *FuturePosition;
        Position CurrentPosition;
        Position LastPosition;

        byte Enable_Pin;
        byte Direction_Pin;
        byte Step_Pin;

        double (*KinematicsCallBack) (Position *SetPosition);

        unsigned long Speed = 2000;
        unsigned long CurrentSpeed=0;
        unsigned double Acceleration = 200;
        unsigned long starting_time;
};

#endif 
