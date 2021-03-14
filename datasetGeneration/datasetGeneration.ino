#include "DHT.h"
#include"Air_Quality_Sensor.h"
#include "TimeLib.h"
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
AirQualitySensor sensor(A2);
float temperature;
float humidity;
int airQuality;
int loudness;
int light;
char dataStr[100] = "";
char buffer[5];

void setup() 
{
  Serial.begin(9600); 
  dht.begin();
  sensor.init();
}

void loop() 
{
  dataStr[0] = 0;
  float temp_hum_val[2] = {0};
  airQuality = sensor.getValue();
  light = analogRead(0);
  loudness = analogRead(1);
  time_t t = now();
  //convert floats to string and assemble c-type char string for writing:
  ltoa( t,buffer,10); //convert long to charStr
  strcat(dataStr, buffer); //add it to the end
  strcat(dataStr, ", "); //append the delimiter
  if(!dht.readTempAndHumidity(temp_hum_val))
  {
    humidity = temp_hum_val[0];
    dtostrf(humidity, 4, 1, buffer);
    strcat(dataStr, buffer); 
    strcat(dataStr, ", ");
    temperature = temp_hum_val[1];
    dtostrf(temperature, 4, 1, buffer);  
    strcat(dataStr, buffer); 
    strcat(dataStr, ", ");
    dtostrf(light, 4, 0, buffer);
    strcat(dataStr, buffer);
    strcat(dataStr, ", "); 
    dtostrf(loudness, 4, 0, buffer);
    strcat(dataStr, buffer);
    strcat(dataStr, ", "); 
    dtostrf(airQuality, 4, 0, buffer);
    strcat(dataStr, buffer);
    strcat(dataStr, 0); //terminate
    Serial.println(dataStr);
  }
  delay(1500);
}
