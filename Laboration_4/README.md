# Laboration 4
Author: Marcus Roos
Date: 20/02-2020

## Environment & Tools
Windows 10 64bit. 
IDE: CLion. 
Environment: MinGW 5.2 
CMake: mingw32 make 3.15.3 
C++ compiler: g++ Debugger: 
MinGW GDB 7.6.1 
Git: Git 2.23.0.windows.1

## Purpose
The purpose of this laboration is to determine the efficiency of different
sorting algorithms, using bubble sort, insertion sort, quick sort as well as 
selection sort. It will be converted to a graph and compared to its 
theoretical time.

## Procedures
First a class had to be made, this class should be created on the heap and
store values. The size of the array will be determined by constants 
5000, 10000, 15000, 20000, 25000, 30000, 35000 and 40000. The values stored
within the array will be in the interval 0 to arrays size - 1. An array of 
size 40000 will therefore get randomly generated values between 0 and 39999. 

The program will then run a four different sorting algorithms on those values, each
time a sorting algorithm has been called, the values within the array need to be
scrambled once more. 10 times per size and sorting algorithm will be made. A 
timer will keep track of how long each method takes, the results will be printed
to a text file which will later on be used to generate a graph. The graph will be
compared to the theoretical efficiency of said method.

## Discussion
Unfortunately I made this task in a bit of a haste as I've been ill for a week
which put me behind on school work. A lot of things could probably have been made 
more efficiently, however I've checked the requirements and I'm decently sure
I've followed the requirements. The purpose of this laboration were to measure
different sorting methods efficiently which has been done. The results are being 
printed to an external log which later got made into a graph to compare values.