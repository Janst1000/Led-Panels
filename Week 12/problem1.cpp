#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
 
/*print function to print results*/
void printLOS(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
/*funtion to compute longest ordered subarray*/
void los(vector<int> arr, int n){
    /*creating a double vector to store the longest sequences*/
    vector<vector<int>> L(n);
 
    /*the longest subarray for teh first number is just the number itself*/
    L[0].push_back(arr[0]);
 
    for (int i = 1; i < n; i++){
        /*repeating for every j that is smaller than i*/
        for (int j = 0; j < i; j++){
            /*if the current element will make the los larger*/
            if ((arr[i] > arr[j]) && (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }
 
        /*The current subsequence will end in the curernt element*/
        L[i].push_back(arr[i]);
    }
 
    /*this creates a vector to save the LOS in*/
    vector<int> max = L[0];
 
    /*now we step through all longest sequences and look for the largest one*/
    for (vector<int> x : L)
        if (x.size() > max.size())
            max = x;
 
    /*printing the LOS*/
    printLOS(max);
}
 
int main(){
    /*getting the input and formatting it to a vector*/
    vector<int> arr;
    string line;
    getline( cin, line );
    istringstream iss( line );
    int number;
    while( iss >> number )
        arr.push_back(number);
    int n = arr.size();
 
    /*calculating the LOS*/
    los(arr, n);
 
    return 0;
}