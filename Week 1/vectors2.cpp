/*
    CH-231-A
    vectors2.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char** argv){
	vector<string> v;
	while(true){
		char input[80] = "";
		cin.getline(input, sizeof(input));
		string str = input;
		if(str == "END"){
			break;
		}
		v.push_back(str);
	}
	if(v.size() >= 5){
		string temp = "";
		temp = v[1];
		v[1] = v[4];
		v[4] = temp;
	} else {
		cout << "One or more strings are missing to swap third and fifth ";
		cout << "position" << endl;
	}

	v[v.size() - 1] = "???";

	for(int i = 0; i < v.size(); i++){
		cout << v[i];
		if(i +1 != v.size()){
			cout << ",";
		}
	}
	cout << endl;
	vector<string>::iterator v_it = v.begin();
	while (v_it != v.end()){
		cout << *v_it;
		if(v_it +1 != v.end()){
			cout << ";";
		}
		v_it++;
	}
	cout << endl;

	v_it = v.end() -1;
	while(v_it+1 != v.begin()){
		cout << *v_it;
		if(v_it != v.begin()){
			cout << " ";
		}
		v_it--;
	}
	cout << endl;
	

	return 0;
}