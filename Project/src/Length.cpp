#include "Length.h"

Length::Length() {
    hour = min = sec = 0;
}

Length::Length(int pHour, int pMin, int pSec) {
    hour = pHour;
    min = pMin;
    sec = pSec;
}

void Length::setHour(int pHour) {
    hour = pHour;
}

void Length::setMin(int pMin) {
    min = pMin;
}
void Length::setSec(int pSec) {
    sec = pSec;
}

bool Length::operator == (const Length& a) const
{
    return hour == a.hour && min == a.min && sec == a.sec;
}

bool Length::operator < (const Length& a) const
{
    return (hour*60 + min*60 + sec) < (a.hour*60 + a.min*60 + sec);
}

Length Length::operator + (const Length& a) const
{
    Length sum;
    sum.sec = sec + a.sec;
    sum.min = min + a.min;
    sum.hour = hour + a.hour + sum.min / 60 + sum.sec / 60;
    sum.min %= 60;
    sum.sec %= 60;
    return sum;
}

std::ostream &operator<<(std::ostream &os, const Length &length){
    os << length.getHour() << '|' << length.getMin() << '|' << length.getSec();

    return os;
}

// Defines operator >>, used for in stream
std::istream &operator>>(std::istream &is, Length &length){
    int tmpInt=0;
    is >> tmpInt;
    is.get();
    int i=1;
    while (tmpInt>=3600){
        length.setHour(i);
        tmpInt = tmpInt-3600;
        i++;
    }
    i=1;
    while (tmpInt>=60){
        length.setMin(i);
        tmpInt = tmpInt-60;
        i++;
    }
    length.setSec(tmpInt);
    return is;
}