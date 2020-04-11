# Final Project
Author: Marcus Roos
Date: 10/04-2020

## Environment & Tools
Windows 10 64bit. 
IDE: CLion. 
Environment: MinGW 5.2 
CMake: mingw32 make 3.15.3 
C++ compiler: g++ Debugger: 
MinGW GDB 7.6.1 
Git: Git 2.23.0.windows.1

## Purpose
The purpose of this laboration is to create a jukebox which will store several albums
as well as songs within this album. We will prove our knowledge regarding
classes, containers, algorithms, read/write from files while maintaining a 
structured code. This program will also be presented orally.
All in all we will bind our previous laborations into one and prove we've
grasped the basics of object oriented programming.

## Procedures
In this laboration we are meant to create a jukebox. It will function pretty much
as a jukebox is meant to, it will store albums and the albums will in turn store songs, 
the songs will contain data regarding the songs title, artist and length. This will
all be handled through different classes. To access the jukebox a menu with two different
submenus will be used, once the program is initially executed your only options will be
to either terminate the program or enter the submenu "file". From said submenu
you will be able to load in a file or return to main menu, this submenu also
contains a third option to save a file to the computer however this
option will be disabled until a file has been loaded in.

Once a file has been loaded in all the options in the main menu will be enabled, as well
as the "save" option in the file menu. A third submenu will also be available and
all its choices will be enabled, this menu will take care of printing
all the albums and their corresponding songs as well as their length to the user. 

To have all this work as we ought to we have to create a few different classes,
the most obvious one being the "album" class, it will contain the name of the album
as a string, as well as a vector containing songs the albums songs. Those songs
will be in the container vector but their type will be a user defined class named
as "Song", this class will store the songs related to this album and it will
keep track of the songs name, which artist wrote it, as well as the songs length.
The user should be able to add an album to the jokebox, this will be done by
having the user input the albums name, then adding any songs they see fit.

The printing sub menu will have to iterate through both these containers to properly
print out the information the user is looking for, for this an actual iterator as well
as automated vector iterator will be used. It should also be possible to delete an
album, the user enters the albums name and gets the entry deleted from the vector as well
as any songs related to it. 

To handle the different menus two different classes will be used, "menu" and "menuitem",
menuitem will take care of enabling or disabling the different menus, while the menu
class will take care of printing menus and handling user choice. In the end all the contents
of the jukebox (album+songs+length) will be saved to a txt file if the user so
choose to use the "save" option. The text file will contain the albums name, 
total amount of songs belonging to that album, as well as every song with
all the relevant information meaning the songs title, artist and its length in seconds.
Once the program is terminated and started up again, it will then be possible to 
load said file into the program to fill the jukebox with albums.


## Discussion