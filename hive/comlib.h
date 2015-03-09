#include <GenericSPI.h>
#include <Arduino.h>
#include <SPI.h>
#include <RF69.h>
#include "engines.h"



#ifndef comlib_h
#define comlib_h

class comlib
{
  public:
	RF69 rf69;
    comlib();
    void init();
    void incomingData(enginesLib &engines);

  private:
  	Print* printer;
};

#endif