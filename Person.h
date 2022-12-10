
#ifndef _PERSON_H_
#define _PERSON_H_

// Person.h

#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

using std::string;

class Person
{
 private:
  std::string person;

public:
  string getName();
  void setName(string person);

  Person();
  Person(string person);
  Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif  /* _PERSON_H_ */
