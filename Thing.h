
#ifndef _THING_H_
#define _THING_H_

// Thing.h

#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <iostream>
#include <fstream>
#include <sstream>
using std::string;

class Thing
{
  private:
    std::string name;
    std::string description;


  public:
    string getName();
    void setName(string name);
    string getDescription();
    void setDescription(string description);
    
    Thing();
    Thing(string name, string description);
    Json::Value dump2JSON();
    virtual bool JSON2Object(Json::Value input);
};

#endif  /* _THING_H_ */

