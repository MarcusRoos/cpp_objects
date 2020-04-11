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
This program had to be built from scratch, very little code, I would dare to say
no code whatsoever were given to us to get going faster. We got a small snippet
to easier understand how the menu and the enabling/disabling features should work.
But it had very little substantial value to get me going. 

To get going with the project a thorough read on the project description was
required, I usually create the menus first but decided against it in this case.
Once I had read the description and watched the video description I decided to
start working from the bottom and up, I built the classes in their hierarchical
order. I first created the time class to handle the length of the songs, after
some struggle I realised I couldn't name the class "time", it automatically
imported the library "time.h", so I had to change it to something else, something
appropriate, I settled for "length" instead. I put together all the 
members and member functions for the class and moved on to the songs class, and 
eventually the albums class, I built them in the same way as the length one.

With the album classes done, the classes that will handle the contents of the
jukebox I created a temporary menu, ignoring the the fact how it should be built up.
I did this as to not waste time on putting together a functioning menu
before I knew if the classes were correctly built, I simply copied one of the
menus from a previous work of mine (Laboration 3). I changed the menu around
and added options to either add an album, print an album or quit the program.
This gave me a foundation to test out the program from and pinpoint if there
were any bugs. 

At a first glance most of the classes seemed to work as they should, as we have 
worked with the same material earlier in the course most of it came natural and
wasn't too unfamiliar. However we have never worked with a vector within a vector,
obviously I had to use iterators to get this working, printing and adding album proved to be
no real hassle at first. I decided to move on to delete an album, it should be really easy
to find an album, an element within the vector and simply delete it however it
proved it be quiet different. I cant simply iterate through the container while using
a find_if statement, I wont be able to delete the element the iterator is currently
looking at as it would break the loop trying to iterate through the vector.
To solve this problem I had to use two different iterators, one which went through
the container, and an actual iterator. Once the desired album were found I had to use the
actual iterators position and from there delete the element, doing it this way
the iterator can keep on going without breaking the inner loop. 

Once I started working on the actual printing of the albums I had the same 
issues as with deleting files, it didn't quiet work out as I anticipated when
I tried to print in the different formats. The printing menu were supposed 
to print in several different ways, the menus which solely printed
the contents of the album was no hassle as I simply had to iterate through
the container and print anything relevant using get member functions. However
for the ones requiring the user to enter an album name as a search term proved 
to be different. I assumed it would be enough to enter the albums name, and once
a match were made it would print that element and only that element but I couldn't
get it to work. So to solve this problem I applied the same method as with deleting an
album, I used an outer actual iterator, and an inner automatic iterator for the container. 
Once a match is found I used the actual iterator to tell the program which element
I want to have printed and where its located. Its basically the same as 
printing a vector using vector[idx], but the index is replaced with the
actual iterators position. 

Getting the formatting done was just a matter of fiddling with the iostream manipulation
library and getting the values down. Once I had one of the printing tables
done I simply applied it to all the different methods and adjusted it as such.

Saving to a file and reading from a file proved to be no problem, we have done so
countless times in the past, and there was no real difference printing a vector
within a vector. I might have done it a bit different than intended but the results
is as it should be. 

At this point I had most of the program done, I hadn't started on the disabling
and enabling of menus, and my search term for printing albums was indeed case sensitive.
I assumed it would be easy to make the search terms case insenstive, all I had to do would
be to use the tolower or toupper function and iterate through the strings, it was not
as easy as I thought. I decided to go for the tolower function (doesnt matter whether
its lower or upper case, as long as its consistent), as I had to convert strings
to lowercase on several different occasions I created a separate function for this.
I realised pretty soon it wasn't as simple as just changing all the letters to 
lowercase while searching, as if I changed both the search term to lowercase
and the albums name to lowercase I would have nothing to print as there is 
nothing in the vector solely with lowercase unless the user entered it as such.
To fix this I once again applied the actual iterator method and iterated through
the vector, after each new album I loaded it into a temporary string and converted it
to a lowercase string which I later used to determine if a match was found, if so,
the program will print the vector at the actual iterators current position.

The whole program was basically done at this point except the features of the menu,
to tackle this I went off the short code snippet we got provided at the start. 
It was basically a bool checking whether its true or false, if true it wont proceed
with the called function, which means no additional user input nor any printing of
submenus will be made. We were allowed add additional menus and functions as we see
fit which made this task a whole lot easier, I called a choice function which
I had located within the menu class, this function will check if a menu is
enabled or not. I added a new member function of the class menu which serves the sole 
purpose of flicking a switch, it will change all the menus to true once its called.
This function will only be called in the file(); function from the user interface
class, the jukebox. I got stuck with this part for a while but upon re-reading the
instructions it said "add appropriate set functions", I went ahead and added
a set function for the bool operator which will iterate through the 
menu and turn all the options to enabled. Before I decided to add this function
I had the menus being activated once the user went into the submenu file but its
supposed to only enable the other menus once a file has been loaded.

It was a big project to tackle for sure, bigger than anyone we've ever had so far,
it certainly proved to combine all our previous experiences and challenges and
a bit extra on top of that. My biggest issue were iterating through containers within
containers, as well as blocking the usage of options once a choice had been made.
If it weren't for the usage of classes this would have been much easier but however that
would clutter the code up by a lot and make it easier to break the whole program, it would
make debugging take much longer as well. If I had program with the length of
a song I know exactly where to look, in the length class. I believe that's one of
the core aspects of object oriented programming, it might take a bit more
practice to get used to and it might be a bigger challenge, more quirks to have
in regard but once you've learned the basics you had a lot more options. Its basically
the same as not using classes except you have to think one step deeper, it's much
harder to break an entire program while using classes, all the parts are
encapsulated and protected. All in all a fun task despite the obstacles I faced, but
it wouldn't be much fun if I didn't have to think and overcome said obstacles.

A bit slow start on my end due to illness and whatnot and I apologize for that,
but I like how the program turned out, I've tried breaking it but have not succeeded yet,
I also put my fiancee on the job (known for exploiting most programs) and it's still running
as it should. There may be a bit more to be done on how the content is being printed, 
but it's nothing I have noticed in any case, it looks like it should
according to the project description. 

I am aiming for an E on this task, due to being way off schedule I unfortunately
need to prioritise differently and catch up with the other courses. It wasn't
entirely clear in the description, but the queue and play parts are entirely for
grades higher than C, so I decided to remove them entirely from the menu as 
it didn't seem to serve any purpose having them lying around with no functionality.