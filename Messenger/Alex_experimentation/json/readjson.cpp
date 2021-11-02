#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
#include "readjson.h"

using namespace std;
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

void  rjson(Business *barr, std::string fileName){
	ifstream ifs(fileName);
	Json::Reader reader;
	Json::Value obj;
	reader.parse(ifs, obj);
	for (int i = 0; i < 10; i++){
		string name = obj["businesses"][i]["name"].asString();
		string address = obj["businesses"][i]["location"]["address1"].asString();
		Business temp(name, address);
		barr[i] = temp;
	//	cout << barr[i].name << " " << barr[i].address << endl;
	}
	//Business bus1(obj["businesses"][0]["name"].asString(), obj["businesses"][0]["location"]["address1"].asString());
	//cout << .name << endl;
	//cout << "First name:" << obj["firstname"].asString() << endl;
}

int main(void){
	Business barr[10];
	rjson(barr, "data.json");
	for(int j=0; j<10; j++){
		cout << "name: " << barr[j].name << "; location: " << barr[j].address << endl;
}
}
