#ifndef DT019G_LENGTH_H
#define DT019G_LENGTH_H
#include <iostream>
class Length {
private:
    int hour, min, sec;

public:

    Length();
    Length(int pHour, int pMin=0, int pSec=0);
    ~Length()=default;
    void setHour(int pHour);
    void setMin(int pMin);
    void setSec(int pSec);
    int getHour() const { return hour; }
    int getMin() const { return min; }
    int getSec() const { return sec; }
    bool operator == (const Length& a) const;
    Length operator + (const Length& a) const;
    bool operator < (const Length& a) const;
};
std::ostream &operator<<(std::ostream &os, const Length &length);
std::istream &operator>>(std::istream &is, Length &length);
#endif
