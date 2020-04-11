//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_JUKEBOX_H
#define DT019G_JUKEBOX_H
#include "Menu.h"
#include "Management.h"
#include "Album.h"
#include <fstream>
#include <vector>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Jukebox

 An user interface, keeps a list of the albums in a vector container, type Album
 Contain objects of type Menu and Album
 The jukebox class is an user interface, its meant to talk to the different
 classes and functions and allows the user to both input data and have data
 printed. This is where all the interaction between the user and the program
 happens.
 It contains several different member functions to take care of the program,
 such as saving to file, reading to file, allows the user to add albums,
 delete albums, print the albums, the songs and their time. All member functions
 of this class is kept private with exception to the default constructor and a
 run function, which will handle all the function calls.
 */
class Jukebox {
private:
    Menu menu, filemenu, printmenu;
    std::vector <Album> albumList;

    /**
* file() calls the submenu file which allows the user to either save, or load
* a file into the vector of albums
*
* @param None.
* @return None.
*/
    void file();

    /**
* print() calls the submenu print which allows the user to print out
     * the album in different fashions
*
* @param None.
* @return None.
*/
    void print();

    /**
* addAlbum() allows the user to add a new album to the vector, will ask the
     * user to enter the name of the album, name of the artist, then enter a
     * loop where the user will input the name of a song and its length in
     * seconds. At the end they get the option to add more songs, or to
     * exit back to the main menu.
*
* @param None.
* @return None.
*/
    void addAlbum();

    /**
* deleteAlbum() allows the user to delete an album from the vector, the user
     * will be asked to enter the name of the album to delete. If said album
     * can be found in the vector it will be deleted and the user will be
     * informed, if the album cannot be found the user will be informed.
*
* @param None.
* @return None.
*/
    void deleteAlbum();

    /**
* printOne(), the user will be asked to enter the name of an album, if said
     * album can be found all relevant information regarding the album
     * will be printed.
*
* @param None.
* @return None.
*/
    void printOne();

    /**
* printAllByName(), all albums in the vector will be printed on the screen
     * for the user to see, they will be sorted by the albums name while
     * being case insensitive as well, descending.
*
* @param None.
* @return None.
*/
    void printAllByName();

    /**
* printAllTime() all the albums will be printed for the user to see, they will
     * be sorted by total length of each album, descending.
*
* @param None.
* @return None.
*/
    void printAllTime();

    /**
* printSimpleName() all the albums will be printed for the user to see, they will
     * be sorted by albums name, case insenstive, only the albums name will be
     * printed.
*
* @param None.
* @return None.
*/
    void printSimpleName();

    /**
* printSimpleTime() all the albums will be printed for the user to see, they will
 * be sorted by albums length, only the albums length will be printed.
*
* @param None.
* @return None.
*/
    void printSimpleTime();

    /**
* open() will open a file with the file name specified as a constant in the
     * management.h header file, this filename is hardcoded to "jukebox.txt"
     * and cannot be altered by the user.
*
* @param None.
* @return None.
*/
    void open();

    /**
* save() will save a file with the file name specified as a constant in the
 * management.h header file, this filename is hardcoded to "jukebox.txt"
 * and cannot be altered by the user.
*
* @param None.
* @return None.
*/
    void save();
public:

    /**
* Default constructor of class Jukebox
*
* @param None.
* @return None.
*/
    Jukebox();

    /**
* run() will start the entire program by calling a menu, this menu will
     * contain a switch and the different options for the user to
     * choose. The menu text isn't printed by this function instead the run
     * function merely contains the switch and will call relevant functions
     * from within, depending on user choice.
*
* @param None.
* @return None. 
*/
    void run();
};
#endif //DT019G_JUKEBOX_H
