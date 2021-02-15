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
	/*creating WindGauge object*/
    WindGauge A(12);

    /*pushing Data*/
    A.currentWindSpeed(15);
    A.currentWindSpeed(16);
    A.currentWindSpeed(12);
    A.currentWindSpeed(15);
    A.currentWindSpeed(15);

    /*dumping*/
    A.dump();
    cout << A.highest() << " ";
    cout << A.lowest() << " ";
    cout << A.average() << endl;

    /*pushing new data*/
    A.currentWindSpeed(16);
    A.currentWindSpeed(17);
    A.currentWindSpeed(16);
    A.currentWindSpeed(16);
    A.currentWindSpeed(20);
    A.currentWindSpeed(17);
    A.currentWindSpeed(16);
    A.currentWindSpeed(15);
    A.currentWindSpeed(16);
    A.currentWindSpeed(20);

    /*dumping data*/
    A.dump();
    cout << A.highest() << " ";
    cout << A.lowest() << " ";
    cout << A.average() << endl;

	return 0;
}