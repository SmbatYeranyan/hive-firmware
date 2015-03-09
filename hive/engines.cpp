#include "engines.h"
#include <Arduino.h>
enginesLib::enginesLib()
{
}

void enginesLib::init(int front, int back, int left, int right){
	throttle = 1000;
	frontEngine = front;
	backEngine = back;
	leftEngine = left;
	rightEngine = right;
	pinMode(frontEngine , OUTPUT); 
	pinMode(backEngine , OUTPUT); 
	pinMode(leftEngine , OUTPUT); 
	pinMode(rightEngine , OUTPUT); 
}

void enginesLib::setEngine(int engine, int speed){
  digitalWrite(engine, HIGH);
  delayMicroseconds(speed);
  digitalWrite(engine, LOW);

} 

void enginesLib::engineSetup(){

	setEngine(frontEngine, 1000);
	setEngine(backEngine, 1000);
	setEngine(leftEngine, 1000);
	setEngine(rightEngine, 1000);

}

 
void enginesLib::runAll(){

	setEngine(frontEngine, throttle	);
	setEngine(backEngine, throttle	);
	setEngine(leftEngine, throttle	);
	setEngine(rightEngine, throttle	);

}		