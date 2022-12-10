#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include "JvTime.h"
#include "GPS.h"
#include "Speed.h"


using std::string;

class autov{
    private:
        CSpeed aspeed;
        GPS distance;
        JvTime time;

    public:
        void resultSpeed(CSpeed sp);
        void resultGPS(GPS lo);
        void resultTime(JvTime ti);
        Json::Value dump2JSON();

};
