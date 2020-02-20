//
// Created by Marcus Roos on 2020-02-20.
// Mittuniversitet
// StudentID: Maro1904
//

#include "sort.h"

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort1(int a[], int n) {
    for(int pass=0; pass < n-1; pass++)
        for(int i=0; i < n-1; i++) {
            if(a[i] > a[i+1])
                swap(a[i], a[i+1]);
        }
}

void selectSort(int a[], int n) {
    for(int i=0; i < n - 1; i++) {
        int smallIdx = i;
        for( int j= i+1; j < n; j++)
            if(a[j] < a[smallIdx])
                smallIdx = j;

        if(smallIdx != i)
            swap(a[i], a[smallIdx]);
    }
}

void insertSort(int a[], int n) {
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
            swap(a[first], a[last]);

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

void q1(int a[], int n) {
    quick1(a,0,n-1);
}

//------------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// printArray
// skriv en heltalsarray p� sk�rmen
// Indata: a       array med heltal
//         n       antal heltal
//         nrOnRow antal tal som skrivs per rad
//         space   antal tecken som reserveras f�r utskrift av varje tal
//                 utskriften h�gerjusteras inom dessa tecken
//-----------------------------------------------------------------------------

void printArray( int a[], int n, int nrOnRow, int space) {
    for(int i=0; i < n; i++) {
        cout << setw(space) << a[i];
        if( (i+1)%nrOnRow == 0)
            cout << endl;
    }
    cout << endl;
}
