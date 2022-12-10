#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Thing.h"
using std::string;

string Thing::getName()
{
  return name;
};

void Thing::setName(string name)
{
  this->name = name;
};

string Thing::getDescription()
{
  return description;
};

void Thing::setDescription(string description)
{
  this->description = description;
};

Thing::Thing(){};
Thing::Thing(string name,string description) {
  setName(name);
  setDescription(description);
}
Json::Value Thing::dump2JSON() {
  Json::Value result;
  if (this->name != "") {
    result["name"] = this->name;
  }
  if (this->description != "") {
    result["description"] = this->description;
  }
  return result;
};


bool
Thing::JSON2Object
(Json::Value input)
{
  bool result = true;

  if ((input.isNull() == true) ||
      (input.isObject() != true))
    {
      return false;
    }

  if (((input["name"]).isString() == true) &&
    ((input["description"]).isString() == true))
  {
    this->name = (input["name"]).asString();
    this->description = (input["description"]).asString();
  
  }
  return true;

}


