//
// Created by Marcus Roos on 2020-02-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_ARRAYSORT_H
#define DT019G_ARRAYSORT_H

#include <cstdlib>

class ArraySort
{
private:
    int* arr;
    size_t maxSize;
    size_t size;
public:
    ArraySort();
    ArraySort (int pNum);
    ArraySort( const ArraySort &a);
    ~ArraySort();

    size_t getMaxSize() const {return maxSize;};
    size_t getSize() const {return size;}
    int getValue( int idx) const; bool addValue(int value);
    void setmaxSize(int pMax);
    void setSize(int pSize);
    const ArraySort &operator=(const ArraySort &a);


}; // End of class ArraySort definition



#endif //DT019G_ARRAYSORT_H
