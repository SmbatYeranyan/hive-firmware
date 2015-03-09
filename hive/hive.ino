#include <RF69.h>
#include "hivelib.h"

#include <SPI.h>

hivelib hive(Serial);

void setup() 
{
  hive.init();
  hive.com.init();
  Serial.println("initialized");
}

void loop()
{
    hive.engines.runAll();
    hive.incomingData();
}

