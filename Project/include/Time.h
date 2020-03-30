
#ifndef DT019G_TIME_H
#define DT019G_TIME_H

class Time {
private:
    int hour, min, sec;

public:

    Time();
    Time(int pHour, int pMin=0, int pSec=0);
    ~Time()=default;
    void setHour(int pHour);
    void setMin(int pMin);
    void setSec(int pSec);
    int getHour() const { return hour; }
    int getMin() const { return min; }
    int getsec() const { return sec; }

};

#endif
