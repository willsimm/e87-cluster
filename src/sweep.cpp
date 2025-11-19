#include <globals.h>

void sweep()
{
    timeAlive=millis();
    if((timeAlive-timeLast > 500) &&  sweepcount<8){
        Serial.println("sweeping");
        timeLast=timeAlive;
        Serial.println(sweepcount);


        g_ignition = true;
        g_engine_running = true;
        g_lights_side = !g_lights_side;
        g_lights_dip = !g_lights_dip;
        g_lights_main = !g_lights_main;
        g_lights_front_fog = !g_lights_front_fog;
        g_lights_rear_fog = !g_lights_rear_fog;
        g_lights_indicators =         random(0,3);
        g_rpm = sweepcount * 1000;
        g_speed =  sweepcount * 10;
        g_fuel = sweepcount * 10;
        g_engine_temperature = sweepcount * 10;
        g_handbrake = !g_handbrake;
        g_abs = !g_abs;
        g_airbag = !g_airbag;
        g_seatbelt = !g_seatbelt;

        g_time_hour++;
        g_time_minute++;
        g_time_second++ ;
        g_time_day++ ;
        g_time_month++ ;
        g_time_year++ ;


        delay(500);
        sweepcount++;
        
    }else if (sweepcount==8){
        Serial.println("reset everything");
        sweepcount++;
    }

}