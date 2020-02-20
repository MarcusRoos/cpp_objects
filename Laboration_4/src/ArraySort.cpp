//
// Created by Marcus Roos on 2020-02-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include "ArraySort.h"

#include <iostream>

using namespace std;

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
    maxSize = pMax;
}

void ArraySort::setSize(int pSize)
{
    size = pSize;
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

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void ArraySort::bubbleSort1(int *a, int n) {
    for(int pass=0; pass < n-1; pass++)
        for(int i=0; i < n-1; i++) {
            if(a[i] > a[i+1])
                swap(a[i], a[i+1]);
        }
}

void ArraySort::selectSort(int *a, int n) {
    for(int i=0; i < n - 1; i++) {
        int smallIdx = i;
        for( int j= i+1; j < n; j++)
            if(a[j] < a[smallIdx])
                smallIdx = j;

        if(smallIdx != i)
            swap(a[i], a[smallIdx]);
    }
}

void ArraySort::insertSort(int *a, int n) {
    if(n > 1) {
        int save, j;
        for(int k = n - 1; k >= 0; k--) {
            j = k+1;
            save = a[k];
            while(j < n && save > a[j]) {
                a[j-1] = a[j];
                j++;
            }
            a[j-1] = save;
        }
    }
}


void quick1(int a[], int first, int last) {
    if(first < last) {
        int low  = first;
        int high = last;
        if(a[first] > a[last])
            std::swap(a[first], a[last]);

        do {

            do {
                low++;
            } while(a[low] < a[first]);


            do {
                high--;
            } while(a[high] > a[first]);


            if(low < high)
                swap(a[low], a[high]);
        } while(low <= high);

        swap(a[first], a[high]);

        quick1(a, first, high-1);
        quick1(a, high+1, last);
    }
}

void ArraySort::q1(int *a, int n) {
    quick1(a,0,n-1);
}