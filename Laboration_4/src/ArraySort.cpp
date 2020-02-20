//
// Created by Marcus Roos on 2020-02-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include "ArraySort.h"

#include <iostream>

using std::cout;
using std::endl;

ArraySort::ArraySort(): maxSize(0), size(0)
{
    arr = nullptr;
}

ArraySort::ArraySort (int pMaxSize): maxSize(pMaxSize), size(0)
{
    arr = new int[maxSize];
}

ArraySort:: ~ArraySort()
{
    delete [] arr; arr = NULL;
    cout << endl << "Running destructor for IntArray with maxSize= " << maxSize << endl;
}

int ArraySort::getValue(int idx) const
{
    return arr[idx];
}

bool ArraySort::addValue(int value)
{
    bool valueAdded = false; if(size < maxSize)
    {
        arr[size] = value; size++;
        valueAdded = true;
    }
    return valueAdded;
}

ArraySort::ArraySort (const ArraySort &a): maxSize(a.maxSize), size(a.size)
{
    arr = new int[a.maxSize]; for (int i=0; i<a.size; i++)
        arr[i] = a.arr[i];
}

void ArraySort::setmaxSize(int pMax)
{
    maxSize = std::move(pMax);
}

void ArraySort::setSize(int pSize)
{
    size = std::move(pSize);
}

const ArraySort &ArraySort::operator=(const ArraySort &a)
{
    if(this != &a) {
        delete[]arr;
        arr = new int[a.maxSize];
        maxSize = a.maxSize;
        size = a.size;
        for (int i = 0; i < a.size; i++)
            arr[i] = a.arr[i];
    }
    return *this;
}

int& ArraySort::operator[] (int idx)
{
    return arr[idx];
}