#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
#include "json.hpp"
#include "readjson.h"

using namespace std;
using json = nlohmann::json;
//class Business {
//	public:
//	string name;
//	string address;
//	Business (){}
//	Business (string x, string y) {
//		name = x;
//		address = y;
//}
//	void toString();
//};

int main(void){
	Business barr[10];
	ifstream ifs("data.json");
	//Json::Reader reader;
	nlohmann:json obj = nlohmann::json::parse(ifs);
	//reader.parse(ifs, obj);
	for (int i = 0; i < 10; i++){
		barr[i].name = obj["businesses"][i]["name"];
		barr[i].address = obj["businesses"][i]["location"]["address1"];
		cout << barr[i].name << " " << barr[i].address << endl;
	}
	//Business bus1(obj["businesses"][0]["name"].asString(), obj["businesses"][0]["location"]["address1"].asString());
	//cout << .name << endl;
	//cout << "First name:" << obj["firstname"].asString() << endl;
}

