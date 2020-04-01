//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Jukebox.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

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
    filemenu.printMenuItems();
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
    /*
    int count=0;
    std::cout << "No.  Title                          Artist          Length\n";
    std::cout << "============================================================\n";
    for (const auto& e : albumList){
        for (const auto& f : e.getSong()){
            count++;
            std::cout << std::left << std::setw(5) << count;
            std::cout << std::left << std::setw(31) << f.getTitle();
            std::cout << std::left<< std::setw(16) <<f.getArtist();
            std::cout << std::left << f.getMin() << ":"<<
            std::setw(2) << std::setfill('0') << std::right << f.getSec() <<  std::endl;
            std::cout << std::setfill(' ');
        }
    }*/
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
    printmenu.addItem("Print simple sorted by album name", true);
    printmenu.addItem("Print simple sorted by album total time", true);
    printmenu.addItem("Back to main menu", true);
}

void Jukebox::addAlbum() {
    using namespace std;
    Album album;
    Song tmpSong;
    std::vector <Song> song;
    cout << "Enter albums name: " << endl;
    string tmpalbum, tmpartist, tmpsong;
    cin >> tmpalbum;
    album.setAlbum(tmpalbum);
    cout << "Enter name of the artist: " << endl;
    std::getline(std::cin,tmpartist);
    cin >> tmpartist;
    int count=0, length=0;
    bool loop=true;
    do {
        count++;
        cout << "Enter name of the song: " << endl;
        cin >> tmpsong;
        cout << "Enter the songs length in seconds: " << endl;
        cin >> length;
        cout << "Add another song to album " << tmpalbum << "? (1/0)\n";
        cin >> loop;
        tmpSong.setLength(length);
        tmpSong.setTitle(tmpsong);
        album.addSong(tmpSong);
    }while(loop);
    albumList.push_back(album);
}

void Jukebox::deleteAlbum() {
    std::cout << "I delete" << std::endl;
}

void Jukebox::printOne() {
    std::cout << "Enter name of album to search for\n";
    std::string albumName;
    std::cin >> albumName;
    for (const auto& i : albumList)
        if (albumName == i.getAlbum()){
        int count=0;
        std::cout << "No.  Title                          Artist          Length\n";
        std::cout << "============================================================\n";
        for (const auto& e : albumList) {
            for (const auto &f : e.getSong()) {
                count++;
                std::cout << std::left << std::setw(5) << count;
                std::cout << std::left << std::setw(31) << f.getTitle();
                std::cout << std::left << std::setw(16) << f.getArtist();
                std::cout << std::left << f.getMin() << ":" <<
                          std::setw(2) << std::setfill('0') << std::right
                          << f.getSec() << std::endl;
                std::cout << std::setfill(' ');
            }
        }
    }
}

void Jukebox::printAllByName() {

}

void Jukebox::printAllTime() {

}

void Jukebox::printSimpleName() {

}

void Jukebox::printSimpleTime() {

}
