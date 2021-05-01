# Dataset Generation Arduino Leonardo + Grove Sensors
An example dataset generation via Grove sensors connected to Arduino Leonardo.

## Features

- Contains **humidity**, **temperature**, **light**, **loudness**, and **air quality** data in order.
- Environment is 25 m2 studio room contains 2 people.
- Data is collected from 10/03/2021 18:36 PM to 11/03/2021 18.36 PM.
- Data might be considered as normal, there are no anomalies created on purpose.
- [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/) is used to generate a CSV file. 
- The **groveHighAccTempDataset** contains timestamp + temperature data. Environment is the same. 

## Sensors Used for Data Generation

- [Grove - Temperature&Humidity Sensor (DHT11)](https://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/)
- [Grove Light Sensor](https://wiki.seeedstudio.com/Grove-Light_Sensor/)
- [Grove - Loudness Sensor](https://wiki.seeedstudio.com/Grove-Loudness_Sensor/)
- [Grove - Air Quality Sensor v1.3](https://wiki.seeedstudio.com/Grove-Air_Quality_Sensor_v1.3/)
- [Grove - Temperature&Humidity Sensor (High-Accuracy &Mini) v1.0](https://wiki.seeedstudio.com/Grove-TemptureAndHumidity_Sensor-High-Accuracy_AndMini-v1.0/)

## My Observations Regarding Sensor Qualities

- All sensors other than light sensor are fairly slow and not sensitive. Those sensors data can be used to examine the effects of inadequate sensors.

