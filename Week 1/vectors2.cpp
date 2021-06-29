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
	/*creating a string vector*/
	vector<string> v;
	/*infinte loop*/
	while(true){
		/*creating a temporary char array to allow spaces in strings*/
		char input[80] = "";
		/*getting the input*/
		cin.getline(input, sizeof(input));
		/*saving the input in a string*/
		string str = input;
		/*checking if the input was END and breaking if that's the case*/
		if(str == "END"){
			break;
		}
		/*otherwise we add the string to the vector*/
		v.push_back(str);
	}
	/*we simply if the vector is large enough to have 5 positions*/
	if(v.size() >= 5){
		/*swapping strings*/
		string temp = "";
		temp = v[1];
		v[1] = v[4];
		v[4] = temp;
	} else {
		/*error message*/
		cout << "One or more strings are missing to swap third and fifth ";
		cout << "position" << endl;
	}

	/*setting the last string to ???*/
	v[v.size() - 1] = "???";

	/*printing with index*/
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
		/*printing a comma if it's not the last element*/
		if(i +1 != v.size()){
			cout << ",";
		}
	}
	cout << endl;

	/*printing with itereator*/
	vector<string>::iterator v_it = v.begin();
	while (v_it != v.end()){
		cout << *v_it;
		/*printing a semicolon if it's not the last element*/
		if(v_it +1 != v.end()){
			cout << ";";
		}
		/*increasing the iterator*/
		v_it++;
	}
	cout << endl;

	/*printing in reverse with the iterator*/
	v_it = v.end() -1;
	while(v_it+1 != v.begin()){
		cout << *v_it;
		/*printing a space if it's not the last element*/
		if(v_it != v.begin()){
			cout << " ";
		}
		/*decreasing the iterator*/
		v_it--;
	}
	cout << endl;
	

	return 0;
}