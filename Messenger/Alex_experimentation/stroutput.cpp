#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(void){
	std::__cxx11::string sname;
	ifstream MyReadFile("demo.txt");
	for (int i = 0; i < 5; i++){
		getline(MyReadFile, sname);
		char c[sname.length()+1];
		strcpy(c, sname.c_str());
		cout << c << endl;
	}

//	for (int j = 0; j < 10; j++){
//		cout << c[10][j] << endl;
//}
}
