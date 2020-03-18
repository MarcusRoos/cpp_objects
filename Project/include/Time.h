//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_TIME_H
#define DT019G_TIME_H
class Time {
private:
    int hour, min, sec;
public:
    Time();
    Time(int pHour=0, int pMin=0, int pSec=0);

    void setHour(int pHour);
    void setMin(int pMin);
    void setSec(int pSec);

    int getHour()const {return hour;}
    int getMin()const {return min;}
    int getSec()const {return sec;}

    void tic();

};
#endif //DT019G_TIME_H
