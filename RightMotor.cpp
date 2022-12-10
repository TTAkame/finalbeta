
// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include <string.h>
#include <map>
#include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
#include "Speed.h"
#include "Thing.h"
#include "autov.h"
#include "Person.h"
#include "hw5server.cpp"
#include "hw5server.h"
#include "hw5client.h"
#include <time.h>

using namespace jsonrpc;
using namespace std;

int main() {

  // set variables from autov
  CSpeed right_speed;
  right_speed.setSpeed("75 mile/h");
  GPS right_gps;
  right_gps.setGPS("3 yard(s)");
  // set time

  autov right_motor;
  right_motor.resultSpeed(right_speed);
  right_motor.resultGPS(right_gps);



  // right motor settings
  Json::Value Helmet;
  Helmet["Helmet"] = "Wearing Helmet";
  Json::Value Health;
  Health["Health"] = "Healthy";





  HttpClient httpclient("http://127.0.0.1:7374");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);


  Json::Value rightmotor;
  Json::Value Vehicle;
  Vehicle["Auto Vehicle"] = right_motor.dump2JSON();
  Vehicle["Vehicle"] = "right Motorcycle";
  // Vehicle["Speed"] = right_speed.dump2JSON();
  // Vehicle["Distance"] = right_gps.dump2JSON();
  // Vehicle["Time"] = ?
  Vehicle["Helmet"] = Helmet;
  Vehicle["Health"] = Health;

Json::Value finish;



  HttpServer httpserver(7376);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  
  
  
  while(s.req!=1){
  
  s.StartListening();

  }
  if(s.req==true){

      try {
      rightmotor = myClient.move("move", "Person",
        Vehicle,
        right_gps.dump2JSON(),
        "Right");
      } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
  std::cout << rightmotor.toStyledString() << std::endl;

  

  try {
      finish = myClient.done();
      } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
  std::cout << finish.toStyledString() << std::endl;


  }

  s.StartListening();

  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  

}
