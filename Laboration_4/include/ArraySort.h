//
// Created by Marcus Roos on 2020-02-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_ARRAYSORT_H
#define DT019G_ARRAYSORT_H

#include <cstdlib>
#include <iomanip>
#include <iostream>

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
    int& operator[] (int idx);
    void bubbleSort1(int a[], int n);
    void selectSort(int a[], int n);
    void insertSort(int a[], int n);
    void q1(int a[], int n);

}; // End of class ArraySort definition


#endif //DT019G_ARRAYSORT_H
