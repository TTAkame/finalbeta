
#ifndef _SPEED_H_
#define _SPEED_H_

#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

using std::string;

class CSpeed
{
 private:
  std::string aspeed;

 public:
  string getSpeed();
  void setSpeed(string aspeed);

  CSpeed();
  CSpeed(string aspeed);
  Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif  /* _SPEED_H_ */



