/*
    CH-231-A
    WindGauge.cpp
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include "WindGauge.h"
#include <cmath>
#include <iostream>

WindGauge::WindGauge(int peroid){
    elements = peroid;
}

void WindGauge::currentWindSpeed(int speed){
    /*checking if the new element would create an overflow*/
    if(Data.size() >= elements){
        Data.pop_back();
    }
    /*pushing data*/
    Data.push_front(speed);
}

int WindGauge::highest() const{
    /*temp variable initialization*/
    int temp_high = -INT_MAX;
    /*go through the whole deque*/
    for(int i = 0; i < Data.size(); i++){
        if(Data[i] >= temp_high){
            temp_high = Data[i];
        }
    }
    return temp_high;

}

int WindGauge::lowest() const{
    /*temp variable initialization*/
    int temp_low = INT_MAX;
    /*go through the whole deque*/
    for(int i = 0; i < Data.size(); i++){
        if(Data[i] <= temp_low){
            temp_low = Data[i];
        }
    }
    return temp_low;
}

int WindGauge::average() const{
    /*temp cariable initialization*/
    int temp_sum = 0;
    /*go through the whole deque*/
    for(int i = 0; i < Data.size(); i++){
        temp_sum += Data[i];
    }
    temp_sum = temp_sum / elements;
    return temp_sum;
}

/*simple printing function*/
void WindGauge::dump() const{
    for(int i = 0; i < Data.size(); i++){
        std::cout << Data[i] << " ";
    }
    std::cout << std::endl;
}