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
#include <time.h>

using namespace jsonrpc;
using namespace std;

// std::map (key, value pairs)
// std::map<std::string, Thing *> Thing_Map;
// std::map<std::string, Person *> Person_Map;

// my location

class Myhw5Server : public hw5Server
{
public:
  Myhw5Server(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value move(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const Json::Value& location,
			   const std::string& object_id);

  virtual Json::Value decision(const int num);

 virtual Json::Value obtain();
  

  virtual Json::Value done();
  virtual Json::Value done2();

  bool is_done = false;
  bool is_done2 = false;
  bool req = false;

  std::map<std::string, Thing *> Thing_Map;
  std::map<std::string, Person *> Person_Map;
};

Myhw5Server::Myhw5Server(AbstractServerConnector &connector, serverVersion_t type)
  : hw5Server(connector, type)
{
  std::cout << "Myhw5Server Object created" << std::endl;
}

// member functions

Json::Value
Myhw5Server::move
(const std::string& action, const std::string& class_id,
 const Json::Value& json_object, const Json::Value& location,
 const std::string& object_id)
{
  // int error_code = 0;
  Json::Value result;
  
  Person * lv_person_ptr;

  if (Person_Map.find(object_id) != Person_Map.end())
  {
    lv_person_ptr = Person_Map[object_id];
  }
  else
	{
	  lv_person_ptr = new Person {};
	  Person_Map[object_id] = lv_person_ptr;
  }
	lv_person_ptr->JSON2Object(json_object);
 
  result = json_object;

  std::cout << result.toStyledString() << std::endl;
  return result;
}

Json::Value
Myhw5Server::done()
{
  // int error_code = 0;
  Json::Value result;
  
  result["done"] = "All data sent.";

  this->is_done = true;

  std::cout << result.toStyledString() << std::endl;
  return result;
}


Json::Value
Myhw5Server::done2()
{
  // int error_code = 0;
  Json::Value result;
  
  result["done"] = "All data sent.";

  this->is_done2 = true;

  std::cout << result.toStyledString() << std::endl;
  return result;
}




Json::Value 
Myhw5Server::decision(const int num)
{
  Json::Value result;
if(num==1){
  result["message"]="I'll hit you";
}
else if(num==0){
  result["message"]="I won't hit you";
}
  std::cout << result.toStyledString() << std::endl;

  return result;
}

Json::Value
Myhw5Server::obtain()
{
  // int error_code = 0;
  Json::Value result;
  
  result["done"] = "pull data request";
  this->req = true;

  std::cout << result.toStyledString() << std::endl;
  return result;
}
