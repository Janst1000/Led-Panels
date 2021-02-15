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

	/*opening file*/
	ifstream fp("data.txt");
	if(!fp.good()){
		cout << "error opening file" << endl;
		return 2;
	}

	/*helper variables*/
	string name;
	string last_name;
	string birthday;

	/*reading until we reach end of file*/
	while(fp >> name){
		fp >> last_name;
		fp >> birthday;
		name = name + " " + last_name;
		/*adding to the map*/
		Data[name] = birthday;
	}

	string input;
	/*reading until exit is entered*/
	while(true){
		getline(cin, input);
		if(input == "exit"){
			break;
		}
		if(Data.find(input) == Data.end()){
			cout << "Name not found!" << endl;
		} else {
			cout << Data[input] << endl << endl;
		}

	}
	fp.close();
	return 0;
}