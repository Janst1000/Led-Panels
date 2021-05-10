#include <iostream>

#define MAX INT_MAX
/*define the size here to keep things simple*/
#define size 6

using namespace std;

int main(int argc, char** argv){

	/*this is the adjecency matrix*/
	int graph[size][size] =	{
		{0, 7, 5, 3, MAX, MAX},
		{7, 0, 4, MAX, MAX, 3},
		{5, 4, 0, 2, MAX, 3},
		{3, MAX, 2, 0, 6, MAX},
		{MAX, MAX, MAX, 6, 0, 6},
		{MAX, 3, 3, MAX, 6, 0}
		};

	int distance[size][size];
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(i == j){
				distance[i][j] = 0;
			} else {
				distance[i][j] = MAX;
			}
		}
	}

	return 0;
}