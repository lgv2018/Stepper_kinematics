#include <Stepper_Function.h>

#define DistancesA 100
#define DistancesB 100

Position position;
Stepper_Function JointA(8 ,9 ,10,&position,CalA);
Stepper_Function JointB(8 ,11,12,&position,CalB);

void setup() 
{
  position.x = 1000;
}

void loop() 
{
   JointA.run();
   JointB.run();
}


double CalA(Position StepPosition)
{
  long x = StepPosition.x;
  long y = StepPosition.y;
  double B = CalB(StepPosition);
  double k1 = DistancesA+DistancesB*cos(B);
  double k2 = DistancesB*sin(B);
  return  atan2(y,x) - atan2(k2,k1);
}

double CalB(Position StepPosition)
{
  long x = StepPosition.x;
  long y = StepPosition.y;
  double c = (x*x+y*y-DistancesA*DistancesA-DistancesB*DistancesB)/(2*DistancesA*DistancesB);
  double s = sqrt(1-c*c);
  if(x>0) s = -s;
  return atan2(s,c);
}