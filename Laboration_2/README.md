# Laboration 2
Author: Marcus Roos
Date: 1/02-2020

## Environment & Tools
Windows 10 64bit. 
IDE: CLion. 
Environment: MinGW 5.2 
CMake: mingw32 make 3.15.3 
C++ compiler: g++ Debugger: 
MinGW GDB 7.6.1 
Git: Git 2.23.0.windows.1

## Purpose
The purpose of this laboration is to create our first very first object and learn
the basics of object oriented programming (oop). We'll be using classes, objects,
encapsulation, as well as having a class within another class.

## Procedures
This task came with 3 different objectives, for these objectives I had to
create separate source files and headers as well as use 3 different main().
For the first two I basically built very simple objects and made sure they worked
as intended through the main() function. Once at the third objective it became clear
as to why the two first objectives were so easy, they were meant to be used at a 
later stage namely in the third task.

For the third task I created yet another header and source file, declared an object
named Person which used the 2 previous classes from the 2 first tasks. A test program
were also created here to make sure everything worked as intended. A vector is made and 
used to store even more objects of the class "Person". I created yet another set of
source files and headers to take care of this. I used a menu to let the user input
the values, ran them through a validation function or made up a new one as needed.
It was very crudely done as the main purpose here (in my opinion) is to learn the laboration
requirements and not how to validate input and keeping the screen neat and clean.

## Discussion
I were very new to objects when this laboration started, I've used basic structs
from the earlier course which were very naked in terms of complexity. I've learned
how to use objects, use get/set, how to print, how a class within another class
works as well as encapsulation.

The biggest issue I had were when I had to store it all in a vector and
iterate through it, however it wasn't such a great hindrance as we've worked with 
specifically vectors earlier. Overall it was a fun task, however initially I 
didn't understand we were required to have 3 separate main(), it seems in the previous
years the tasks came in a zip which contained all required files.