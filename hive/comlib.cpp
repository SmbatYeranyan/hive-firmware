#include "comlib.h"
#include <Arduino.h>
#include <SPI.h>
#include <RF69.h>
#include "engines.h"

comlib::comlib()
{

}

void comlib::init(){
	if (!rf69.init()){
	  Serial.println("RF69 init failed");
	}else{
	  Serial.println("RF69 worked");  
	}

	if (!rf69.setFrequency(433))
		Serial.println("RF69 setFrequency failed");
	if (!rf69.setModemConfig(RF69::GFSK_Rb250Fd250))
		Serial.println("RF69 setModemConfig failed");

	uint8_t key[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
	                0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
	rf69.setEncryptionKey(key);

	#if 0
	// For compat with RFM69 Struct_send
	rf69.setModemConfig(RF69::GFSK_Rb250Fd250);
	rf69.setPreambleLength(3);
	uint8_t syncwords[] = { 0x2d, 0x64 };
	rf69.setSyncWords(syncwords, sizeof(syncwords));
	rf69.setEncryptionKey((uint8_t*)"thisIsEncryptKey");
	#endif
}

void comlib::incomingData(enginesLib &engines){
	if (rf69.available())
  {
    // Should be a message for us now   
    uint8_t buf[RF69_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf69.recv(buf, &len))
    {
        char * curData = (char*)buf;
        char * temp;
        char *throttleString = strtok_r(curData,",",&temp);
        char *yawString = strtok_r(temp,",",&temp);
        char *pitchString = strtok_r(temp,",",&temp);
        engines.yaw= atoi(yawString );
        engines.throttle = atoi(throttleString);

        if (engines.throttle ==  0){
          engines.throttle   = 1000;
        }else{
          engines.throttle   = (1000 + (engines.throttle   *2.5 ));

        }
   
    }
    else
    {
    }
  }


} 
		