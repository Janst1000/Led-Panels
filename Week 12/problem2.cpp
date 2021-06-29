#include <iostream>
#include <sstream>
#include <vector>
#include <deque>


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

/*

I did not get my algorithm to work yet unfortunately. But getting the input
works and the triangle can be printed

void solve(vector<vector<int>> &tri, deque<int> &path){
	int n = tri.size();
	for(int i = n - 1; i >= 0; i--){
		for(int j = i; j >= 0; j--){
			if( tri[i + 1][j])
		}
	}
}
*/

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
		}
		cin.clear();
	}

	printTri(tri);

	deque<int> path(lines - 1);


	return 0;
}