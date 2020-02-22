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

For comparing the times on graphs I got very similar results for all the sorting
algorithms with exception of quicksort, for the lower sized arrays it seemed my computer
did the job faster than the theoretical time, but the bigger the array got, the 
slower my computer seemed to handle the job. I read up a bit on quick sorting
and it seems it depends on how the array is split when the sorting is done.
The theoretical time itself is very linear, I hope my calculations are correct and seeing
as my sorting for 5000 array size couldn't be measured in milliseconds I had to divide
by 7 when calculating the average value. I got 4.6054E-9 as a result, using this to
calculate the theoretical value I used the formula (k*n*log2(n)) which in the
case of a 40000 sized array would be (4.6054E-9*40000*log2(40000)) which gave
me the theoretical time of 0.0028 seconds, however my actual result took 0.0043 seconds.
When looking at other theoretical times of the quicksort agorithm my calculations
seem to be very close though.