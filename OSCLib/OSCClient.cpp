/*
 
 ArdOSC 2.1 - OSC Library for Arduino.
 --> Modifications made to the Version retrieved from https://github.com/watterott/RedFly-Shield
 -->  Adapted for the WiFlyHQ Library
 --> Plenty of modifications have been made by Watterott and me, so most errors you will encounter are probably not the original authors fault...
 -------- Lisence -----------------------------------------------------------
 
 ArdOSC
 
 The MIT License
 
 Copyright (c) 2009 - 2011 recotana( http://recotana.com )　All right reserved
 
 */

#include <stdlib.h>

#include "OSCCommon/OSCClient.h"




OSCClient::~OSCClient(void)
{

}


uint8_t* OSCClient::send(OSCMessage *_message)
{
    int result = 1;
    uint16_t msgSize;
    uint8_t *sendData;

    msgSize  = _message->getMessageSize();
    sendData = (uint8_t*) calloc(msgSize, 1);

    if( sendData == NULL )
    {
     // return -1;
    }

    if( encoder.encoder(_message, sendData) < 0 )
    {
      //free(sendData);
     // return -2;
    }

//	while(millis()-lastSendMillis<TimeoutMillis){
		//if(lastSendMillis>millis())lastSendMillis=millis(); //be prepared for millis() overflow...
////	}; //wait until last package is flushed
   // wiFly->write(sendData, msgSize);
   // wiFly->flush();
    //free(sendData);
	//lastSendMillis=millis();
    return sendData;//result;
}
/*
uint8_t* OSCClient::sendInt(int value, char* adress){
  OSCMessage loacal_mes;
  loacal_mes.beginMessage(adress);
  loacal_mes.addArgInt32(value);
  return(this->send(&loacal_mes));
}

uint8_t* OSCClient::sendFloat(float value, char* adress){
  OSCMessage loacal_mes;
  loacal_mes.beginMessage(adress);
  loacal_mes.addArgFloat(value);
  return(this->send(&loacal_mes));
}
 */
