/*
    CH-231-A
    testWindGauge.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <iostream>
#include <deque>
#include "WindGauge.h"

using namespace std;
int main(int argc, char** argv){
	WindGauge A(12);
    for(int i = 0; i < 15; i++){
        A.currentWindSpeed(i);
    }
    
    cout << A.highest() << endl;
    cout << A.lowest() << endl;
	return 0;
}