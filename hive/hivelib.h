
#ifndef hivelib_h
#define hivelib_h
#include <Arduino.h>
#include "engines.h"
#include "comlib.h"


class hivelib
{
  public:
    hivelib(Print &print);
    void init();
    void engineSetup();
    void incomingData();
    void runEngines(int throttle);
    enginesLib engines;
    comlib com;
  private:

  	Print* printer;
};

#endif