#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>

using namespace std;

int main(int argc,char** argv){
	/*time based seed*/
	srand(time(NULL));
	/*opening file to write to*/
	ofstream out("numbers.txt");
	if(!out.good()){
		cerr << "file opening went wrong" << endl;
		return 2;
	}

	/*getting input for parameters*/
	int elements = 0;
	int num = 0;
	int step = 0;
	cin >> elements;
	cin >> num;
	cin >> step;

	/*creating the random number sequences*/
	for(int i = 0; i < num; i ++){
		for(int j = 0; j < elements; j++){
			int random_number = rand() % (100 + elements);
			out << random_number << " " ;
		}
		out << endl;
		cout << "finished " << i << " lines" << endl;
		elements += step;
	}

	cout << "done" << endl;

	return 0;
}