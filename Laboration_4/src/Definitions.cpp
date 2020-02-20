#include <iostream>
#include "ArraySort.h"
#include "RandomGenerator.h"
#include <chrono>
#include <ostream>
#include <fstream>

using namespace std;

void assignmentFunction(int a, int b) {
    auto * a1 = new ArraySort(a); // Creates new object on the heap
    int tmpNum=0; // Numbers for formatting
    double average = 0;// Numbers for formatting
    cout << "***********************************************\n";
    if(b==0) { // Checks param from function, will print depending on param
        cout << "Testing on " << a << " elements using insert sort\n\n";
    }
    if (b==1) {
        cout << "Testing on " << a << " elements using quick sort\n\n";
    }
    if(b==2) {
        cout << "Testing on " << a << " elements using bubble sort\n\n";
    }
    if(b==3) {
        cout << "Testing on " << a << " elements using select sort\n\n";
    }

    for (int i = 0; i < 10; i++) { // Iteration to test 10 times per value
        for(int k=0; k < a; k++) { // Refill array with new values every lap
            a1->addValue(RNG(a));
        }
        std::cout << std::fixed << std::setprecision(6);
        auto timeStart = std::chrono::high_resolution_clock::now(); // Timer
        if(b==0) { // Depending on param, will use the correct sorting method
            a1->insertSort(a);
        }
        if (b==1) {
            a1->q1(a);
        }
        if(b==2) {
            a1->bubbleSort1(a);
        }
        if(b==3) {
            a1->selectSort(a);
        }
        auto timeEnd = std::chrono::high_resolution_clock::now(); // End timer
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                timeEnd - timeStart).count(); // Calc duration
        double seconds = 1.0 * duration / 1000; // Convert from ms to sec
        average += seconds;
        std::cout << "Duration = "
                  << seconds
                  << " [s]" << ", test number " << i + 1 << "/10"
                  << std::endl;
        tmpNum = a; // save number for printing
        a1->setSize(0); // reset size to 0 to fill array with new values
    }
    double time = average / 10; // calc average time
    cout << "\nAverage time = " << time << " [s]" << endl;
    cout << "***********************************************\n\n\n";
    ofstream outFile;
    string writeFile = ("Output.txt"); // Stream for writing

    outFile.open(writeFile, ios::app); // Appends to file
    if(b==0) { // Depending on sorting method, write to file
        a1->insertSort(a);
        outFile << "insertionsort";
        outFile << char(9);
    }
    if (b==1) {
        a1->q1(a);
        outFile << "quicksort";
        outFile << char(9);
    }
    if(b==2) {
        a1->bubbleSort1(a);
        outFile << "bubblesort";
        outFile << char(9);
    }
    if(b==3) {
        a1->selectSort(a);
        outFile << "selectsort";
        outFile << char(9);
    }
    // Output to file, correct formatting
    outFile << tmpNum;
    outFile << char(9);
    outFile << fixed << std::setprecision(6) << time << "\n";
    outFile.close();
}

void pauseFunction(const std::string& text){ /* Function used when program
 * should wait for user input before it continues */
    std::cout << text; // Prints function parameter on screen
    std::cin.clear(); // Clear stream
    std::cin.sync(); // Synchronizes the input stream
    std::cin.get(); // Waits for user input before it continues
    std::cin.clear(); // Clear stream once again to remove leftovers
    std::cin.sync(); // Synchronizes the input stream
}