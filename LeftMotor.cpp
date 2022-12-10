
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
  CSpeed left_speed;
  left_speed.setSpeed("60 mile/h");
  GPS left_gps;
  left_gps.setGPS("2 yard(s)");
  // set time

  autov left_motor;
  left_motor.resultSpeed(left_speed);
  left_motor.resultGPS(left_gps);



  // left motor settings
  Json::Value Helmet;
  Helmet["Helmet"] = "No Helmet";
  Json::Value Health;
  Health["Health"] = "Healthy";



  HttpClient httpclient("http://127.0.0.1:7374");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);


  // Set all data for right motor
  Json::Value leftmotor;
  Json::Value Vehicle;
  Vehicle["Auto Vehicle"] = left_motor.dump2JSON();
  Vehicle["Vehicle"] = "Left Motorcycle";
  // Vehicle["Speed"] = left_speed.dump2JSON();
  // Vehicle["Distance"] = left_gps.dump2JSON();
  // Vehicle["Time"] = ?
  Vehicle["Helmet"] = Helmet;
  Vehicle["Health"] = Health;

 Json::Value finish;



  HttpServer httpserver(7375);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  
  
  
  while(s.req!=1){
  
  s.StartListening();

  }


  if(s.req==true){

      try {
      leftmotor = myClient.move("move", "Person",
        Vehicle,
        left_gps.dump2JSON(),
        "Left");
      } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
  std::cout << leftmotor.toStyledString() << std::endl;

  

  try {
      finish = myClient.done2();
      } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
  std::cout << finish.toStyledString() << std::endl;


  }

  s.StartListening();

  std::cout << "Hit enter to stop the server" << endl;
  getchar();



}
