/*
    CH-231-A
    vectors1.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char** argv){
	vector<string> vec;
	string temp = "";
	while(true){
		cin >> temp;
		if(temp == "END"){
			break;
		}
		vec.push_back(temp);
	}

	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << endl;

	vector<string>::iterator vec_it = vec.begin();
	while(vec_it != vec.end()){
		cout << *vec_it;
		if(vec_it + 1 != vec.end()){
			cout << ",";
		}
		vec_it++;
	}

	cout << endl;

	return 0;
}