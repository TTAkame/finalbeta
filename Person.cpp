#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Person.h"
using std::string;

string Person::getName()
{
  return person;
};

void Person::setName(string person)
{
  this->person = person;
};

Person::Person() {}
Person::Person(string person) 
{
  setName(person);
}

Json::Value Person::dump2JSON() {
  Json::Value result;
  if (this->person != "") {
    result["person"] = this->person;
  }
  return result;
};

bool
Person::JSON2Object
(Json::Value input)
{
  bool result = true;

  if ((input.isNull() == true) ||
      (input.isObject() != true))
    {
      return false;
    }
  if ((input["person"]).isString() == true) {
    this->person = (input["name"]).asString();
  }

  return true;

}
