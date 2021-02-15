/*
    CH-231-A
    WindGauge.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include "WindGauge.h"
#include "cmath"

WindGauge::WindGauge(int peroid){
    elements = peroid;
}

void WindGauge::currentWindSpeed(int speed){
    if(Data.size() >= elements){
        Data.pop_back();
    }
    Data.push_front(speed);
}

int WindGauge::highest() const{
    int temp_high = -INT_MAX;
    for(int i = 0; i < Data.size(); i++){
        if(Data[i] >= temp_high){
            temp_high = Data[i];
        }
    }
    return temp_high;

}

int WindGauge::lowest() const{
    int temp_low = INT_MAX;
    for(int i = 0; i < Data.size(); i++){
        if(Data[i] <= temp_low){
            temp_low = Data[i];
        }
    }
    return temp_low;
}