#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "autov.h"


using std::string;


Json::Value autov::dump2JSON() {
    Json::Value result;
    
    result["speed"] = aspeed.dump2JSON();

    // aspeed -> result["Speed"];
    
    result["distance"] = distance.dump2JSON();

    JvTime *currentTime = getNowJvTime();
    

    result["time"] = currentTime->dump2JSON();
    
    // std::string *str_ptr = this->getTimeString();
    // result["time"] = (*str_ptr);

    return result;
}


void autov::resultSpeed(CSpeed sp){
    aspeed = sp;
}
void autov::resultGPS(GPS lo){
    distance = lo;
}
void autov::resultTime(JvTime ti){
    ti = time;
}
