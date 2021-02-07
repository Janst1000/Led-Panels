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
	/*creating a vector*/
	vector<string> vec;
	/*initializing a string*/
	string temp = "";
	/*infinite loop for input*/
	while(true){
		cin >> temp;
		/*checking if input is END*/
		if(temp == "END"){
			/*breaking out of the loop if it is*/
			break;
		}
		/*otherwise we push the word to the back*/
		vec.push_back(temp);
	}

	/*printing the words with the vector index*/
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << endl;

	/*printing the word with the iterator*/
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