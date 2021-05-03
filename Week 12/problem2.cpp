#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

void printTri(vector<vector<int>> &tri){
	int n = tri.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cout << tri[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char** argv){
	int lines;
	cout << "How many lines does the triangle have?" << endl;
	cin >> lines;
	cin.clear();

	vector<vector<int>> tri(lines);

	for(int i = 0; i < lines; i++){
		int temp = 0;
		for(int j = 0; j <= i; j++){
			cin >> temp;
			tri[i].push_back(temp);
			cout << "values: "<< i << " " << j << endl;
		}
		cin.clear();
	}

	printTri(tri);

	return 0;
}