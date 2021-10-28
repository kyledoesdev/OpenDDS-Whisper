//this is by no means my final version: i will continue to improve this
//to make this less messy and more efficient

//this is a fragment from DevGuideExamples/DCPS/Messenger/Publisher.cpp
//we are looking for the loop that starts after the Messenger fields are
// initialized

#include <cstring>
#include <fstream>
int ACE_TMAIN(int argc, ACE_TCHAR *argv[]);
// Publisher.cpp code, which we don't need for our purposes

std::string sname[10]; //the number of strings will be made configurable later
//but hard-coded for now

ifstream MyReadFile("demo.txt");
for (int = 0; i < 10; i++) {

//code

//I randomly chose to edit the message.from field, 
//but it can be any string field really

++message.count;
++message.subject_id;
getline(MyReadFile, sname[i]);
const char* name = sname[i].c_str();
message.from = name;

//... remaining code of Publisher.cpp
//output of this is successful
