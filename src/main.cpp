#include <Arduino.h>

#include <configuration.h>
#include <globals.h>
#include <canbus.h>
#include <serial.h>

MCP_CAN CAN(SPI_CS_PIN);
bool cansuccess=false;
void setup()
{
    delay(2000);
    Serial.begin(SERIAL_BAUD_RATE);
    Serial.setTimeout(250);
    
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
    //g_rpm = millis();
    //g_speed = 7000/240 * millis();
    //delay(500);
    /*SH;1;1;1;1;1;1;1;3;2000;100;50;50;1;1;1;1;12;34;56;01;01;2025;*/
}

