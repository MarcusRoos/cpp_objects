# Laboration 1
Author: Marcus Roos
Date: 26/1-2020

## Environment & Tools
Windows 10 64bit. 
IDE: CLion. 
Environment: MinGW 5.2 
CMake: mingw32 make 3.15.3 
C++ compiler: g++ Debugger: 
MinGW GDB 7.6.1 
Git: Git 2.23.0.windows.1

## Purpose
The purpose of this laboration is to get an understanding of how pointers within
C++ work. 

## Procedures
The program is meant to accept user input as an integer, use this integer to
initialize the size of an array, the array will then be filled with random numbers
ranging from -5000 to 5000. Once the array has been filled, an iteration using
pointers will determine the maximum, as well as minimum value within the array.
Every single element in the array shall be printed on the screen, up to a 
maximum of 200 per page, if 200 is met, the program will require user input
to continue.

I made a quick validator to make sure the user input a positive integer when
creating the size of the array.

A random generator had to be added to fill the random, for this the <random>
library was used, using time as a random factor. A simple for-loop was created
to fill the array, within this for-loop the numbers will also be printed with
appropriate formatting. To keep track of how many results are shown per page. 
I decided to create a separate counter to count upwards to 200, if 200 is 
met the program will pause, inform the user how many elements remain in the
array, as well as require any input before its continues.

To find the maximum, minimum and sum of arrays pointers were used to create a 
loop, I decided to declare and initialize a new pointer called "end", pointing towards the array +
size, it's used to determine how many elements the array contains. The for loop
declares a new variable which is constantly pointing towards the arrays elements, as
long as the aforementioned pointer is smaller than the 'end' pointer the loop
will iterate. To determine the maximum and minimum value I simply had to compare
the current value in the element to the maximum and minimum value respectively,
if its either bigger or smaller, assign the value its currently pointing at, to the 
max and min value respectively. The sum will be calculated by appending whatever
value the pointer is pointing at to a new variable called "sum".

In the end, both max, min and sum will be printed on the screen and the user will
once again be informed the program is finished, user input will be required to
exit the program.

## Discussion
Having worked with pointers previously I had at least some knowledge as how
I would go about solving this problem. I had however never used pointers in an iteration
previously, it did not prove a challenge however creating pointers to print the max
and min value did prove a challenge. I had to first create pointers, initialize them 
to point towards the array, then within the loop they needed to point towards the correct 
value and only change whenever the pointer pointed at either a bigger or smaller value.

To pause the program when either 200 elements have been printed, or the array
has finished I used one of my self made pause functions. I like it because it does
not use any SYSTEM syntax which would only have worked on windows machines, but it's
cross platform. It simply clears the stream, syncs and await user input, as no
input validation is done anything will do, that includes even just an enter.

I decided to use the <random> library to generate random numbers between the
desired interval, I also included the <ctime> library solely for this random
generator to have a base to work from. The numbers will be generated depending
on the current time which makes for almost certain random generated numbers,
however a custom generator could have been made, incorporating the time as well as
several variables.

Regarding the pointers I'm still relatively new to C++, and I fail to see their usage 
within loops, however I am also sure their usage as iterators will be more
clear further in either this course or a more advanced course.

The purpose of the laboration has been fulfilled, I have learned more about pointers
than I did before, the program does what it should. It uses user input to determine
size of an array, fills said array with random numbers, array is later iterated
through using solely pointers. Pointers will be declared and initialized to
point towards either the biggest or smallest number and it will be printed out 
in the end of the program.