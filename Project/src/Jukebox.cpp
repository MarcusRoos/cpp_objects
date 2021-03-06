//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Jukebox.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>

/**
The run function, this function will be called in the main program, from here a
 it will enter a switch which will call another function from the menu class.
 Here the user will be able to choose what they would like to do with the
 program, at first only the first "file" option will be option, once a file
 has been loaded in from the first option the rest of the menus will open
 up.
*/
void Jukebox::run() {
    bool again = true;
    do
    {
        menu.printMenuItems();
        switch(menu.menuChoice())
        {
            case 1:
                file();
                break;
            case 2:
                addAlbum();
                break;
            case 3:
                deleteAlbum();
                break;
            case 4:
                print();
                break;
            case 5:
                again = false;
                break;
        }
    }while(again);
}
/**
The file function, used to call the submenu file from where the user is allowed
 to make another choice. The "save" option will initially be disabled, until
 the user choose the first option "open". Once this option has been chosen all
 the menus will be opened, even in the print submenu and the mainmenu.
*/
void Jukebox::file() {
    // I skipped a loop here as user should be returned to main menu.
        filemenu.printMenuItems();
        switch(filemenu.menuChoice())
        {
            case 1:
                open();
                break;
            case 2:
                save();
                break;
            case 3:
            default:
                // Returns to main menu
                break;
        }
}

/**
The print function, used to call the submenu print in which the user will
 be able to print the albums from the jukebox in different fashions.
 Depending on the users input here the albums will be printed in 5 different
 ways, either by searching for the albums name or simply all the albums
 currently in the jukebox.
*/
void Jukebox::print() {
    bool again = true;
    do
    {
        printmenu.printMenuItems();
        switch(printmenu.menuChoice())
        {
            case 1:
                std::cout << "Print one album\n";
                printOne();
                break;
            case 2:
                std::cout << "Print all sorted by album name\n";
                printAllByName();
                break;
            case 3:
                std::cout << "Print all sorted by album total time\n";
                printAllTime();
                break;
            case 4:
                std::cout << "Print simple sorted by album name\n";
                printSimpleName();
                break;
            case 5:
                std::cout << "Print simple sorted by album total time\n";
                printSimpleTime();
                break;
            case 6:
                again = false;
                std::cout << "Back to main menu\n";
                break;
        }
    }while(again);
}

/**
The default constructor, will initialize the objects menu, filemenu and print
 with their relevant values.
*/
Jukebox::Jukebox() {
    menu.setTitle("**** JUKEBOX ****");
    menu.addItem("File...", true);
    menu.addItem("Add an album", false);
    menu.addItem("Delete an album", false);
    menu.addItem("Print...", false);
    menu.addItem("Exit", true);
    filemenu.setTitle("**** FILE ****");
    filemenu.addItem("Open", true);
    filemenu.addItem("Save", true);
    filemenu.addItem("Back to main menu", true);
    printmenu.setTitle("**** PRINT ****");
    printmenu.addItem("Print one album", true);
    printmenu.addItem("Print all sorted by album name", true);
    printmenu.addItem("Print all sorted by album total time", true);
    printmenu.addItem("Print simple sorted by album name", true);
    printmenu.addItem("Print simple sorted by album total time", true);
    printmenu.addItem("Back to main menu", true);
}

/**
The addAlbum function, here the user will be able to add new albums and songs.
 The user will be asked to enter the name of the album, followed by the name
 of the artist, from here on out the function will enter a loop. Within this
 loop the user will be able to add a song and the length of the song,
 if the user so wishes they are able to keep adding songs to the album
 until they decide to exit the program, at which point they will be returned
 to the main menu.
*/
void Jukebox::addAlbum() {
    using namespace std;
    Album album;
    Song tmpSong;
    std::vector <Song> song;
    string tmpalbum, tmpartist, tmpsong;
    cout << "Enter albums name: " << endl;
    std::getline(std::cin >> std::ws, tmpalbum);
    album.setAlbum(tmpalbum);
    cout << "Enter name of the artist: " << endl;
    std::getline(std::cin >> std::ws, tmpartist);
    tmpSong.setArtist(tmpartist);
    int length=0;
    bool add=true;
    do {
        cout << "Enter name of the song: " << endl;
        std::getline(std::cin >> std::ws, tmpsong);
        cout << "Enter the songs length in seconds: " << endl;
        cin >> length;
        while (std::cin.fail() || length<=0 || length>9999){
            std::cout << "Wrong input, enter a value between 1 and 9999.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> length;
        }
        cout << "Add another song to album " << tmpalbum << "? (Y/N)\n";
        char again=0;
        bool loop=true;
        do {
            cin >> again;
            again = toupper(again);
            if (again != 'Y' && again != 'N') { // If input is not valid, run
                cin.clear(); // Clear cin buffer
                cin.ignore(
                        reinterpret_cast<streamsize>
                        (numeric_limits<streamsize>::max), '\n');
                // Ignore cin stream
                cout << "Invalid input\n";
            }
            if (again == 'N') { // If no, break both loops
                loop = false;
                add = false;
            }
            if (again == 'Y') { // If yes, break inner loop, keep outer true
                loop = false;
                add = true;
            }
        }while(loop);
        tmpSong.setLength(length);
        tmpSong.setTitle(tmpsong);
        album.addSong(tmpSong);
    }while(add);
    albumList.push_back(album);
}

/**
The deleteAlbum function. Once called the user will be asked to enter the name
 of an album, the function will then iterate through the album container until
 a match is found. If a match is found it will be deleted from the vector.
 This is done by using an actual iterator outside the inner iterator which
 is iterating through the vector, this is done so we can get an index as to
 where the found album is located. Once a match has been found the index from
 the actual iterator will be used to call the erase function.
*/
void Jukebox::deleteAlbum() {
    std::cout << "Enter name of album to delete\n";
    std::string albumName, compare, tmpAlbum;
    bool print = true;

    std::getline(std::cin >> std::ws, albumName);
    std::string tmpName = albumName;
    albumName = lowercase(albumName);
    for (auto pos = albumList.begin(); pos != albumList.end();) {
        for (auto &it : albumList) {
            compare = it.getAlbum();
            tmpAlbum = it.getAlbum();
            compare = lowercase(compare);
            if (compare == albumName) {
                pos = albumList.erase(pos);
                std::cout << "Successfully deleted album " << tmpAlbum << std::endl;
                print = false;
            }
            else
                pos++;
        }
    }
    if (print){
        std::cout << "Could not find album "<< tmpName << std::endl;
    }
}

/**
The printOne function, allows the user to enter the name of an album to
 search for. If a match is found within the albumList vector the said
 album will be printed on the screen with formatting. The search is done
 case insensitive which means a search of for instance "abBey roAd" will
 still match with the album "Abbey Road".
*/
void Jukebox::printOne() {
    std::cout << "Enter name of album to search for\n";
    std::string albumName, compare;
    std::getline(std::cin >> std::ws, albumName);
    albumName = lowercase(albumName);
    for (auto pos = albumList.begin(); pos != albumList.end();) {
        if (pos != albumList.end()) {
            int count = 0;
            printHeader();
            for (const auto &e : albumList) {
                compare = e.getAlbum();
                compare = lowercase(compare);
                for (const auto &f : e.getSong()) {
                    if (albumName == compare) {
                        count++;
                        std::cout << std::left << std::setw(5) << count;
                        std::cout << std::left << std::setw(55) << f.getTitle();
                        std::cout << std::left << std::setw(16)
                                  << f.getArtist();
                        if (f.getHour() >= 1)
                            std::cout << std::left << f.getHour() << ":";
                        std::cout << std::left << f.getMin() << ":" <<
                                  std::setw(2) << std::setfill('0')
                                  << std::right
                                  << f.getSec() << std::endl;
                        std::cout << std::setfill(' ');
                    }
                }
            }
        }

        pauseFunction("Press any key to continue...\n");
        break;
    }
}

/**
The printAllByName function, this function will print all the albums
 within the jukebox sorted by albums name. The sorting is done case insensitive
 and all the relevant information will be printed on the screen in an easy to
 read formatting.
*/
void Jukebox::printAllByName() {
        sort(albumList.begin(), albumList.end(),
             [](const Album &a, const Album &b) {
            std::string tmpA = a.getAlbum(), tmpB = b.getAlbum();
                 tmpA = lowercase(tmpA);
                 tmpB = lowercase(tmpB);
                    return tmpA < tmpB;
             });
        int count = 0;
        printHeader();
        for (const auto &e : albumList) {
            if (e.getAlbum().length() > 0) {
                std::cout << "--- Album name: " << e.getAlbum() << " ---"
                          << std::endl;
            }
            for (const auto &f : e.getSong()) {
                count++;
                std::cout << std::left << std::setw(5) << count;
                std::cout << std::left << std::setw(55) << f.getTitle();
                std::cout << std::left << std::setw(16) << f.getArtist();
                if (f.getHour() >= 1)
                    std::cout << std::left << f.getHour() << ":";
                std::cout << std::left << f.getMin() << ":" <<
                          std::setw(2) << std::setfill('0') << std::right
                          << f.getSec() << std::endl;
                std::cout << std::setfill(' ');
                if (count == e.getSong().size()){
                    std::cout << std::endl;
                    count=0;
                }
            }
        }
        pauseFunction("Press any key to continue...\n");
}

/**
The printAllTime function, this function will print all the albums
 within the jukebox sorted by albums total length. The albums will be printed
 with an easy to read formatting, the total amount of time per album is
 printed out at the end of each album.
*/
void Jukebox::printAllTime() {
    std::sort(albumList.begin(), albumList.end());
    int count=0, tmpSize=0;
    printHeader();
    for (const auto& e : albumList) {
        int time=0;
        std::cout << "--- Album name: " << e.getAlbum() << " ---"
                  << std::endl;
        for (const auto &f : e.getSong()) {
            tmpSize++;
            count++;
            std::cout << std::left << std::setw(5) << count;
            std::cout << std::left << std::setw(55) << f.getTitle();
            std::cout << std::left << std::setw(16) << f.getArtist();
            if (f.getHour()>=1)
                std::cout << std::left << f.getHour() << ":";
            std::cout << std::left << f.getMin() << ":" <<
                      std::setw(2) << std::setfill('0') << std::right
                      << f.getSec() << std::endl;
            std::cout << std::setfill(' ');
            time += f.getLength();
            if (tmpSize == e.getSong().size()){
                tmpSize = 0;
                std::cout << "LANGD:  "<< time << std::endl;
                std::cout << std::endl;
            }
        }
    }
    pauseFunction("Press any key to continue...\n");
}

/**
The printSimpleName function, this function will print all the albums
 within the jukebox sorted by albums name. The sorting is done case insensitive,
 unlike the first print all album function this one will only print the
 albums name and nothing else.
*/
void Jukebox::printSimpleName() {
    sort(albumList.begin(), albumList.end(),
         [](const Album &a, const Album &b) {
             std::string tmpA = a.getAlbum(), tmpB = b.getAlbum();
             tmpA = lowercase(tmpA);
             tmpB = lowercase(tmpB);

             return tmpA < tmpB;

         });
    std::cout << "Sorted by album name\n";
    for (const auto &e : albumList) {
        if (e.getAlbum().length() > 0)
            std::cout << "Album name: " << e.getAlbum() << std::endl;
    }
    pauseFunction("Press any key to continue...\n");
}

/**
The printSimpleTime function, this function will print all the albums
 within the jukebox sorted by albums total length. The albums will be printed
 with an easy to read formatting, only the albums name and total time will
 be printed on the screen unlike the previous print time function.
*/
void Jukebox::printSimpleTime() {
    std::sort(albumList.begin(), albumList.end());
    for (const auto &e : albumList) {
        int time = 0;
        if (e.getAlbum().length() > 0)
            std::cout << "ALBUM: " << e.getAlbum() << std::endl;
        for (const auto &f : e.getSong())
            time += f.getLength();
        if (time>0)
        std::cout << "TOTAL TIME: " << time << std::endl;
    }
    pauseFunction("Press any key to continue...\n");
}

/**
The open function, once called it will open a file on the computer, the name
 will be determined by the program and is hardcoded into to code, under the
 constant name "filename". Once the file has been opened it will read until
 end of file and store its contents in albumList, using overloaded operators
 from the underlying classes.
*/
void Jukebox::open() {
    using namespace std;
    Album tmpAlbum;
    ifstream inFile(filename, ios::in);
    albumList.clear();
    menu.setenableMenu();
    if (inFile.is_open()) {
        while (inFile >> tmpAlbum) {
            albumList.push_back(tmpAlbum);
            Album tmpAlbumReset;
            tmpAlbum = tmpAlbumReset;
        }
        if (albumList.empty())
            pauseFunction("File is empty, but has been loaded up. "
                          " Press any key to continue. \n");
        else
            pauseFunction("File loaded. Press any key to continue.\n");
    }
    inFile.close();
}

/**
The save function, once called it will save a file to the computer, the name
 will be determined by the program and is hardcoded into to code, under the
 constant name "filename". If the file does not exist on the computer it
 will be created, once created the file will be opened and the contents
 of the albumList vector will be written onto the file with a pre-determined
 formatting.
*/
void Jukebox::save() {
    using namespace std;
    if (albumList.empty())
        pauseFunction("No albums currently stored in the jukebox. "
                      "Press any key to continue.\n");
    else {
    ofstream outFile(filename, ios::out);
        pauseFunction("File saved. Press any key to continue.\n");
        for (const auto &album : albumList) {
            outFile << album;
        }
        outFile.close();
    }
}