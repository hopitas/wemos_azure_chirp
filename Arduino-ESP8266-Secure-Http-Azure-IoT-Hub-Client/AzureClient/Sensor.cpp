#include "Sensor.h"


void Sensor::measure(){
  temperature = 25;
  humidity = 50;
  pressure = 1000;
  wlevel = 0;
}

char* Sensor::toJSON() {
/*  https://github.com/bblanchon/ArduinoJson/wiki/Memory-model
    Have allowed for a few extra json fields that actually being used at the moment
*/
  
  StaticJsonBuffer<JSON_OBJECT_SIZE(16)> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
 

  root["Utc"] = getISODateTime();
  root["Celsius"] = temperature / 10;
  root["Moisture"] = (moisture - 300) / 4;
  root["Waterlevel"] = wlevel;
//  root["hPa"] = pressure;
  root["Light"] = 65535 / (65535 - light) * 100;
  root["Geo"] = geo;
  root["Schema"] = 1;

  //instrumentation
//  root["WiFi"] = telemetry->WiFiConnectAttempts;
  root["Mem"] = ESP.getFreeHeap();
  root["Id"] = ++msgId;

  root.printTo(buffer, sizeof(buffer));

  return buffer;
}

char* Sensor::getISODateTime() {
  sprintf(isoTime, "%4d-%02d-%02dT%02d:%02d:%02d", year(), month(), day(), hour(), minute(), second());
  return isoTime;
}


