#include <Arduino.h>

#include <configuration.h>
#include <globals.h>
#include <canbus.h>
#include <serial.h>

MCP_CAN CAN(SPI_CS_PIN);
bool cansuccess=false;
void setup()
{
    delay(5000);
    Serial.begin(SERIAL_BAUD_RATE);
    
    byte b = CAN.begin(MCP_ANY, CAN_100KBPS, CAN_CLOCK);
      


    if ( b == CAN_OK)
    {
        Serial.println("MCP2515 Initialized successfully");
        cansuccess=true;

    }else {

        Serial.println(b);
    }

    CAN.setMode(MCP_NORMAL);
}

void loop()
{
    sendCanBus();
    readSerial();
    if (!cansuccess){
    //Serial.println("fail");
    }
}

