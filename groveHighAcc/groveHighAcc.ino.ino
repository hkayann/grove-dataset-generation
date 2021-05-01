#include <Wire.h>
#include "DS1307.h"
#include <TH02_dev.h>

DS1307 clock;//define a object of DS1307 class
char clockArray[5];
char tempArray[5];
char dataArray[20] = "";
void setup() {
    Serial.begin(9600);
    delay(150);
    TH02.begin();
    clock.begin();
    clock.fillByYMD(2021, 04, 24); //Jan 19,2013
    clock.fillByHMS(15, 11, 00); //15:28 30"
    clock.setTime();//write time to the RTC chip
}
void loop() {
    clock.getTime();
    dataArray[0] = 0;
    int realYear = clock.year + 2000;
    itoa(realYear, clockArray, 10);
    strcat(dataArray, clockArray);
    itoa(clock.month, clockArray, 10);
    strcat(dataArray, clockArray);
    itoa(clock.dayOfMonth, clockArray, 10);
    strcat(dataArray, clockArray);
    itoa(clock.hour, clockArray, 10);
    strcat(dataArray, clockArray);
    itoa(clock.minute, clockArray, 10);
    strcat(dataArray, clockArray);
    itoa(clock.second, clockArray, 10);
    strcat(dataArray, clockArray);
    strcat(dataArray, ", ");
    float temper = TH02.ReadTemperature();
    dtostrf(temper, 5, 2, tempArray);
    strcat(dataArray, tempArray);
    
    strcat(dataArray, 0);
    Serial.println(dataArray);
    delay(5000);

}
