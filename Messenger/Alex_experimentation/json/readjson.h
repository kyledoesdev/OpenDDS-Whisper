#ifndef READJSON_H

#define READJSON_H

#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
class Business {
	public:
	std::string name;
	std::string address;
	Business(){}
	Business(std::string x, std::string y){
		name = x;
		address = y;
	}
};
void rjson(Business*, std::string);

#endif
