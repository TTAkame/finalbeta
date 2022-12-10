#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Speed.h"
using std::string;

string CSpeed::getSpeed()
{
  return aspeed;
};

void CSpeed::setSpeed(string aspeed)
{
  this->aspeed = aspeed;
};

CSpeed::CSpeed() {}
CSpeed::CSpeed(string aspeed) 
{
  setSpeed(aspeed);
}

Json::Value CSpeed::dump2JSON() {
  Json::Value result;
  if (this->aspeed != "") {
    result["speed"] = this->aspeed;
  }
  return result;
};

bool
CSpeed::JSON2Object
(Json::Value input)
{
  bool result = true;

  if ((input.isNull() == true) ||
      (input.isObject() != true))
    {
      return false;
    }
  if ((input["speed"]).isString() == true) {
    this->aspeed = (input["speed"]).asString();
  }

  return true;

}
