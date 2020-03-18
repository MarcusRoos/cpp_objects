
#include <iostream>
#include <iomanip>    // setw, setfill
#include "Time.h"
using namespace std;


Time::Time() {
    hour = min = sec = 0;
}

Time::Time(int pHour, int pMin, int pSec) {
    setHour(pHour);
    setMin(pMin);
    setSec(pSec);
}

void Time::setHour(const int pHour) {
    hour = (pHour >= 0 && pHour < 24) ? pHour : -1;
}

void Time::setMin(const int pMin) {
    min = (pMin >= 0 && pMin < 60) ? pMin : -1;
}
void Time::setSec(const int pSec) {
    sec = (pSec >= 0 && pSec < 60) ? pSec : -1;
}
