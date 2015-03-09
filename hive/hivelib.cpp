#include "hivelib.h"
#include <Arduino.h>

hivelib::hivelib(Print &print)
{
	printer = &print;
}

void hivelib::init(){
	//Setup Pins for engines
	engineSetup();
}

void hivelib::engineSetup(){
	engines.init(9,8,7,6);
	delay(100);
	engines.engineSetup();
}
void hivelib::incomingData(){

	com.incomingData(engines);
	
}


void hivelib::runEngines(int throttle){
	engines.setEngine(engines.frontEngine, throttle);
	engines.setEngine(engines.backEngine, throttle);
	engines.setEngine(engines.leftEngine, throttle);
	engines.setEngine(engines.rightEngine, throttle);
}
