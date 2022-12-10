
#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "GPS.h"
using std::string;

string GPS::getGPS()
{
  return distance;
};

void GPS::setGPS(string distance)
{
  this->distance = distance;
};

GPS::GPS() {}
GPS::GPS(string distance) 
{
  setGPS(distance);
}

Json::Value GPS::dump2JSON() {
  Json::Value result;
  if (this->distance != "") {
    result["Distance"] = this->distance;
  }
  return result;
};

bool
GPS::JSON2Object
(Json::Value input)
{
  bool result = true;

  if ((input.isNull() == true) ||
      (input.isObject() != true))
    {
      return false;
    }
  if ((input["Distance"]).isString() == true) {
    this->distance = (input["Distance"]).asString();
  }

  return true;

}
