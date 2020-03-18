
#ifndef DT019G_TIME_H
#define DT019G_TIME_H

class Time {
private:
    int hour, min, sec;

public:

    Time();
    Time(int pHour, int pMin=0, int pSec=0);

    void setHour(int pHour);
    void setMin(int pMin);
    void setSec(const int pSec);

    int getHour() const { return hour; }
    int getMin() const { return min; }
    int getMin() const { return sec; }

};

#endif
