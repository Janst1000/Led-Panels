/*
    CH-231-A
    problem_5.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char** argv){
	/*creating map object*/
	map<string, string> Data;
	Data["Jan Steinmüller"] = "15.05.2001";

	if(Data.find("Jan Steinmüller") == Data.end()){
		cout << "Name not found" << endl;
	} else {
		cout << Data["Jan Steinmüller"] << endl;
	}
	return 0;
}