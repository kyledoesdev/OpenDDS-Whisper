#ifndef READJSON_H

#define READJSON_H

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

#endif
