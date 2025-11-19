#include <Arduino.h>
#include <EasyEspNow.h>
#include <configuration.h>
#include <globals.h>
#include <canbus.h>
#include <serial.h>
#include <sweep.h>


MCP_CAN CAN(SPI_CS_PIN);


void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);
    Serial.println("hello");
    //timeLast=timeAlive=millis();
  

    /*if (CAN.begin(MCP_ANY, CAN_100KBPS, CAN_CLOCK) == CAN_OK)
    {
        Serial.println("MCP2515 Initialized successfully");
    }

    CAN.setMode(MCP_NORMAL);*/

}

void loop()
{
    //sendCanBus();
    readSerial();
    sweep();
}

