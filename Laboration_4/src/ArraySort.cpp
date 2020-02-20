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

void ArraySort::setSize(int pSize)
{
    size = pSize;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void ArraySort::bubbleSort1(int n) {
    for(int pass=0; pass < n-1; pass++)
        for(int i=0; i < n-1; i++) {
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
}

void ArraySort::selectSort(int n) {
    for(int i=0; i < n - 1; i++) {
        int smallIdx = i;
        for( int j= i+1; j < n; j++)
            if(arr[j] < arr[smallIdx])
                smallIdx = j;

        if(smallIdx != i)
            swap(arr[i], arr[smallIdx]);
    }
}

void ArraySort::insertSort(int n) {
    if(n > 1) {
        int save, j;
        for(int k = n - 1; k >= 0; k--) {
            j = k+1;
            save = arr[k];
            while(j < n && save > arr[j]) {
                arr[j-1] = arr[j];
                j++;
            }
            arr[j-1] = save;
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

void ArraySort::q1(int n) {
    quick1(arr,0,n-1);
}