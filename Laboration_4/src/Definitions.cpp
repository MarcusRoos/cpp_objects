#include <iostream>
#include "ArraySort.h"
#include "RandomGenerator.h"
#include <chrono>
#include <ostream>
#include <fstream>

using namespace std;

void assignmentFunction(int a, int b) {
    ArraySort a1(a);

    double average = 0;
    if(b==0) {
        cout << "Testing on " << a << " elements using insert sort\n";
    }
    if (b==1) {
        cout << "Testing on " << a << " elements using quick sort\n";
    }
    if(b==2) {
        cout << "Testing on " << a << " elements using bubble sort\n";
    }
    if(b==3) {
        cout << "Testing on " << a << " elements using select sort\n";
    }
    for (int i = 0; i < 10; i++) {
        for(int k=0; k < a; k++) {
            int x = RNG(a);
            a1.addValue(x);
        }
        cout << "\nRandom pick from index maxsize - 1 = " << a1.getValue(a-1) << endl;
        std::cout << std::fixed << std::setprecision(6);
        auto timeStart = std::chrono::high_resolution_clock::now();
        if(b==0) {
            a1.insertSort(a);
        }
        if (b==1) {
            a1.q1(a);
        }
        if(b==2) {
            a1.bubbleSort1(a);
        }
        if(b==3) {
            a1.selectSort(a);
        }
        auto timeEnd = std::chrono::high_resolution_clock::now();
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                timeEnd - timeStart).count();
        double seconds = 1.0 * duration / 1000;
        average += seconds;
        std::cout << "Duration = "
                  << seconds
                  << " [s]" << ", test number " << i + 1 << "/10"
                  << std::endl;
    }

    double time = average / 10;
    cout << "\nAverage time = " << time << " [s]" << endl;
    ofstream outFile;
    string writeFile = ("Output.txt");

    outFile.open(writeFile, ios::app);
    if(b==0) {
        a1.insertSort(a);
        outFile << "insertionsort";
        outFile << char(9);
    }
    if (b==1) {
        a1.q1(a);
        outFile << "quicksort";
        outFile << char(9);
    }
    if(b==2) {
        a1.bubbleSort1(a);
        outFile << "bubblesort";
        outFile << char(9);
    }
    if(b==3) {
        a1.selectSort(a);
        outFile << "selectsort";
        outFile << char(9);
    }
    outFile << char(9);
    outFile << a1.getSize();
    outFile << char(9);
    outFile << std::setprecision(6) << time << "\n";
    outFile.close();
}