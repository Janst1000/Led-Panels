/*
    CH-231-A
    WindGauge.h
    Jan Steinmueller
    j.steinmueller@jacobs-university.de
*/
#include <deque>
using namespace std;

class WindGauge {
	public:
		WindGauge(int period = 12);
		void currentWindSpeed(int speed);
		int highest() const;
		int lowest() const;
		int average() const;
		void dump() const;
	private:
		deque<int> Data;
		int elements;
};