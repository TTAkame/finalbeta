
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
// #include "Person.h"
#include "Speed.h"
#include "Thing.h"
#include "autov.h"
#include "hw5server.cpp"
#include "hw5server.h"
#include "hw5client.h"
#include <time.h>

using namespace jsonrpc;
using namespace std;

int main() {

  
  Person WOLF, GM;
  WOLF.setName("The wolf");
  GM.setName("Grandma");

  HttpClient httpclient("http://127.0.0.1:7377");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value GPS;
  GPS["location"] = "Grandma's Home outside of the wood with three large oak trees nearby";


  HttpServer httpserver(7376);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)

  while(s.is_done == false)
  {
    s.StartListening();
    // std::cout << "Hit enter to stop the server" << endl;
    // getchar();

  }

    s.StopListening();


  //getchar();
  
  // access all the values in Person map
  // for(auto it = s.Person_Map.begin(); it != s.Person_Map.end(); it++) {
  //   // keys.push_back(it->first);

  //   try {
  //         myv = myClient.move("move", "Person",
  //           s.Person_Map[it->first]->dump2JSON(),
  //           GPS,
  //           "LRRH");
  //       } catch (JsonRpcException &e) {
  //         cerr << e.what() << endl;
  //       }
  //   std::cout << myv.toStyledString() << std::endl;

  Json::Value result;
  result["Person 1"] = WOLF.dump2JSON();
  result["Person 2"] = GM.dump2JSON();
  result["Location"] = GPS;

  try {
    myv = myClient.move("move", "Person",
      result,
      GPS,
      "LRRH");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }



  Json::Value finish;

  try {
    finish = myClient.done();
    } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
    

}
