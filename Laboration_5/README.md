# Laboration 5
Author: Marcus Roos
Date: 18/03-2020

## Environment & Tools
Windows 10 64bit. 
IDE: CLion. 
Environment: MinGW 5.2 
CMake: mingw32 make 3.15.3 
C++ compiler: g++ Debugger: 
MinGW GDB 7.6.1 
Git: Git 2.23.0.windows.1

## Purpose
The purpose of this laboration is to create a dynamically linked list and use it
as a queue to simulate a housing queue. The list will follow a FIFO type and
to accomplish this we will be using a pointer to iterate through the list.

## Procedures
The "Person" class from previous laborations will be used to store a persons
information in the housing queue so a copy of relevant files were made 
(Names/Address/Person). Next up an interface which the user will interact with
were made, the interface is a class itself and will handle all the input/output
as to protect the program and its internal structure. 

To create a queue we will be creating a couple of new files queue.h (header), and
queue.cpp (source). These two files will contain several classes which all have
different tasks. The QList class will handle the list itself, the and house queue, 
the QIterator will act as a pointer to help iterate through the list. 
The Node class will act as a container to store information regarding the person 
itself and address to the next object in the list.

## Discussion
A lot of code were given at the start of the laboration as to ease the specific 
purposes of the laboration. With these code snippets we were pretty much given
the code to queue people, deque people, delete from the list. We were also
given code snippets of overloading a few operators namely prefix and postfix
increment (++).

The hard part with this laboration was to get a proper list up and running from
the interface program, how to store the information and be able to iterate and
find whatever you were searching for. One of the menu options prompted the user
to enter a persons social security number, the program would then find this person
in the queue, print all relevant information as well as the persons position
in the housing queue. I had a bit of struggle to get this working as it should, 
and it turns out my problem wasn't with my current code but with overloading
the comparison operator (==) within the Person class. It took quiet a bit of time
to find out where the issue came from, but thanks to this very issue I learned
about breakpoints while debugging code and how effective they can be while debugging.

I had a few issues with deleting a person from the queue as well, deque and enqueue
worked as it should. However one of the options were meant to take a persons
social security number, find them in the list and delete them, even if it so
meant deleting a person from the middle of the queue. The problem once again
wasn't with my code but with the comparison operator in the Person class. 
Once I got it sorted out my code worked as it should, saving and loading from files
were made easy as we've done it several times in the past and I basically just had
to copy-paste from previous laborations and make a few adjustments.

So far I have worked with vectors or arrays but never actual user implemented
lists so I wasn't too familiar with how I would go about adding a person to
the list. Turns out it isn't all too difficult, the list itself simply stores one
single object (Person), it's the same as having a list (or array even), store a
simple integer, increasing it size by one and adding another one. 

My understanding for user created objects have definitely increased with
this laboration and I've stopped seeing them as simply several different data types
and being able to distinguish when it is in fact solely one data type as in this
case. It is not different than storing a pre-determined data type within an
array or vector, what we did in this laboration were create our own array/vector
but also a queue using FIFO.