
#ifndef _GPS_H_
#define _GPS_H_

#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

using std::string;

class GPS
{
 private:
  std::string distance;

 public:
  string getGPS();
  void setGPS(string distance);

  GPS();
  GPS(string distance);
  Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif  /* _GPS_H_ */
