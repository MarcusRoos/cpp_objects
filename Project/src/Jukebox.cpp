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
    printmenu.addItem("Print simple sorted by album name ALSO TEST", true);
    printmenu.addItem("Print simple sorted by album total time", true);
    printmenu.addItem("Back to main menu", true);
}

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

void Jukebox::deleteAlbum() {
    std::cout << "Enter name of album to delete\n";
    std::string albumName, compare, tmpAlbum;
    bool print = true;

    std::getline(std::cin >> std::ws, albumName);
    std::string tmpName = albumName;
    std::for_each(albumName.begin(), albumName.end(),
                  [](char &b) {
                      b = tolower(b);
                  });
    for (auto pos = albumList.begin(); pos != albumList.end();) {
        for (auto &it : albumList) {
            compare = it.getAlbum();
            tmpAlbum = it.getAlbum();
            std::for_each(compare.begin(), compare.end(),
                          [](char &c) {
                              c = tolower(c);
                          });
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



void Jukebox::printOne() {
    std::cout << "Enter name of album to search for\n";
    std::string albumName;
    std::getline(std::cin >> std::ws, albumName);
    auto it = find_if(albumList.begin(), albumList.end(),
            [&albumName](const Album& a) {return a.getAlbum() == albumName;});
        if (it != albumList.end()){
        int count=0;
        std::cout << "No.  Title                          Artist          Length\n";
        std::cout << "============================================================\n";
        for (const auto& e : albumList) {
            for (const auto &f : e.getSong()) {
                if (albumName == e.getAlbum()) {
                    count++;
                    std::cout << std::left << std::setw(5) << count;
                    std::cout << std::left << std::setw(31) << f.getTitle();
                    std::cout << std::left << std::setw(16) << f.getArtist();
                    if (f.getHour() >= 1)
                        std::cout << std::left << f.getHour() << ":";
                    std::cout << std::left << f.getMin() << ":" <<
                              std::setw(2) << std::setfill('0') << std::right
                              << f.getSec() << std::endl;
                    std::cout << std::setfill(' ');
                }
            }
        }
    }
    pauseFunction("Press any key to continue...\n");
}

void Jukebox::printAllByName() {
    sort(albumList.begin(), albumList.end(),
         [](const Album& a, const Album& b) {
             return a.getAlbum() < b.getAlbum();
         });
    int count=0;
    std::cout << "No.  Title                          Artist          Length\n";
    std::cout << "============================================================\n";
    for (const auto& e : albumList) {
        if(e.getAlbum().length() >0)
        {
            std::cout << "=== Album name: " << e.getAlbum() << " ==="<< std::endl;
        }
        for (const auto &f : e.getSong()) {
            count++;
            std::cout << std::left << std::setw(5) << count;
            std::cout << std::left << std::setw(31) << f.getTitle();
            std::cout << std::left << std::setw(16) << f.getArtist();
            if (f.getHour()>=1)
                std::cout << std::left << f.getHour() << ":";
            std::cout << std::left << f.getMin() << ":" <<
                      std::setw(2) << std::setfill('0') << std::right
                      << f.getSec() << std::endl;
            std::cout << std::setfill(' ');
        }
    }
    pauseFunction("Press any key to continue...\n");
}

void Jukebox::printAllTime() {
    std::sort(albumList.begin(), albumList.end());
    int count=0;
    std::cout << "No.  Title                          Artist          Length\n";
    std::cout << "============================================================\n";
    for (const auto& e : albumList) {
        int time=0;
        std::cout << "Album name: "<< e.getAlbum() << std::endl;
        for (const auto &f : e.getSong()) {
            count++;
            std::cout << std::left << std::setw(5) << count;
            std::cout << std::left << std::setw(31) << f.getTitle();
            std::cout << std::left << std::setw(16) << f.getArtist();
            if (f.getHour()>=1)
                std::cout << std::left << f.getHour() << ":";
            std::cout << std::left << f.getMin() << ":" <<
                      std::setw(2) << std::setfill('0') << std::right
                      << f.getSec() << std::endl;
            std::cout << std::setfill(' ');
            time += f.getLength();
        }
        // Comment off to show total time of the album
      //  std::cout << "Total time: " << time << std::endl;
    }
    pauseFunction("Press any key to continue...\n");
}

void Jukebox::printSimpleName() {
    sort(albumList.begin(), albumList.end(),
         [](const Album &a, const Album &b) {
             return a.getAlbum() < b.getAlbum();
         });
    std::cout << "Sorted by album name\n";
    for (const auto &e : albumList) {
        if (e.getAlbum().length() > 0)
            std::cout << "Album name: " << e.getAlbum() << std::endl;
    }
    pauseFunction("Press any key to continue...\n");
}

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
    }
    inFile.close();
    pauseFunction("File loaded. Press any key to continue.\n");
}

void Jukebox::save() {
    using namespace std;
    ofstream outFile(filename, ios::out);
    for (const auto& album : albumList) {
        outFile << album;
    }
    outFile.close();
    pauseFunction("File saved. Press any key to continue.\n");
}

/*
 * void Jukebox::deleteAlbum() {
    std::cout << "Enter name of album to delete\n";

    std::string albumName, compare;
    std::getline(std::cin >> std::ws, albumName);
    for (auto &it : albumList){
        compare = it.getAlbum();
        std::for_each(compare.begin(), compare.end(),
                      [](char & c){
                          c = tolower(c);
                      });
        if (compare == albumName){
            albumList.erase(albumList.begin(), albumList.end());
            break;
        }
        std::cout << "Compare : " << compare << std::endl;
    }
    std::cout << "Album name: " <<albumName << std::endl;
}
 */