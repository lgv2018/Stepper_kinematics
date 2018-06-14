
#ifndef position_h
#define position_h

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <wiring.h>
#endif

class Position
{
    public:
        long X;
        long Y;
        long Z;
        long A;
        long B;
        long C;
        long D;
        long E;
        long F;
        long G;
        
    private:
        
};

#endif 
