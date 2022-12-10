
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
#include "Person.h"
#include "Thing.h"
#include "hw5server.cpp"
#include "hw5client.h"
#include <time.h>

using namespace jsonrpc;
using namespace std;

int main() {
  
 


  HttpClient httpclient("http://127.0.0.1:7376");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);




 Json::Value dec;
  int ed=1;
  Json::Value finish;

    try {
      finish = myClient.obtain();
      } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
  std::cout << finish.toStyledString() << std::endl;



 
  


   HttpServer httpserver(7374);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  
  
  
    while(s.is_done==false){
      
      s.StartListening();

    }





 HttpClient httpclient2("http://127.0.0.1:7375");
  hw5Client myClient2(httpclient2, JSONRPC_CLIENT_V2);

  



 Json::Value dec2;
  int op=1;
  Json::Value finish2;

    try {
      finish2 = myClient2.obtain();
      } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
  std::cout << finish2.toStyledString() << std::endl;


  
  
    while(s.is_done2==false){
      
      s.StartListening();

    }









    try {
      dec = myClient.decision(ed);
      } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
  std::cout << dec.toStyledString() << std::endl;  

}
