# Laboration 3
Author: Marcus Roos
Date: 16/02-2020

## Environment & Tools
Windows 10 64bit. 
IDE: CLion. 
Environment: MinGW 5.2 
CMake: mingw32 make 3.15.3 
C++ compiler: g++ Debugger: 
MinGW GDB 7.6.1 
Git: Git 2.23.0.windows.1

## Purpose
The purpose of this laboration is to learn the basics of overloading
operators and apply their new uses within objects, specifically in this
example a vector of objects.

## Procedures
This laboration required us to use the three previously created classes from 
laboration 2. These classes included a class for Names, (first name, last name),
Address, (street, city, postcode) and a class for Person which
consisted of the two aforementioned classes plus shoe size and social security
number. In this laboration two new classes were created which were meant
to bind the person class together, create a vector, allow the user to add new
people to the vector of object person, sort the list, print the list, as well as
save it and load it from a file. 

For this two new source files and two new headers were made (UserInterface and
PersonList). User Interface only had the task to print information to the user and
let the user input as well as call all relevant functions for the selected task.
A menu were printed and the user were allowed to choose their approach.
Meanwhile the person list class did all the work, it made the sorting, spoke to
the underlying classes, contained the vector itself.

A third source file "Client Program" were made, its only use it to call the user 
interface which in turn start the program.

## Discussion
The reason as to why overloading operators is an integral part of programming,
C++, is clear as day after this task. They aren't being overloaded globally but
locally, and within the classes where the overloading was made, it drastically
reduces the work for the coder. For this task we simply compared a few values to one another,
but in a larger scale you might wish to sort several different things in different
orders, in such a case overloading the operators will make quick work of such
a task.

For this task barely any of the previous experiences helped, everything was
done either through classes of objects of classes. Nothing is left global, instead
everything is done locally and either passes as arguments, parameters or return
values, a lot of encapsulation was also made, specifically the three 
underlying classes we used to keep track of the persons, a middle class
which performed all the heavy lifting, then a user interface which
the user could interact with, we even had a program which called the
user interface. Its becoming clear why object oriented has gained so much
traction, it's hard to destroy an integral part of the program by simply 
changing a line of code. Either the compiler will complain, or just a small
part of the program will act out. 