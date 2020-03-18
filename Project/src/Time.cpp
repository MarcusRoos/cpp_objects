//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Time.h"

Time::Time() {
    hour = min = sec = 0;
}

Time::Time(int pHour, int pMin, int pSec) {
    setHour(pHour);
    setMin(pMin);
    setSec(pSec);
}

void Time::setHour(int pHour) {
    if(pHour >= 0 && pHour < 24) hour = pHour;
    else
        hour = -1;
}

void Time::setMin(int pMin) {
    if(pMin >= 0 && pMin < 60) min = pMin;
    else
        min = -1;
}

void Time::setSec(int pSec) {
    if(pSec >= 0 && pSec < 60) sec = pSec;
    else
        sec = -1;
}

void Time::tic() {

}
