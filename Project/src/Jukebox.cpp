//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Jukebox.h"
#include <iostream>
#include <iomanip>

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
    printmenu.printMenuItems();
    int count=0;
    std::cout << "No.    Title                          Artist          Length\n";
    std::cout << "============================================================\n";
    for (const auto& e : albumList){
        for (const auto& f : e.getSong()){
            count++;
            std::cout << std::left << std::setw(7) << count;
            std::cout << std::left << std::setw(31) << f.getTitle();
            std::cout << std::left<< std::setw(18) <<f.getArtist();
            std::cout << f.getMin() << ":"<<
            std::setw(2) << std::setfill('0') << std::right << f.getSec() <<  std::endl;
            std::cout << std::setfill(' ');
        }
    }
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
    string tmpAlbum, tmpartist, tmpsong;
    cin >> tmpAlbum;
    album.setAlbum(tmpAlbum);
    cout << "Enter name of the artist: " << endl;
    cin >> tmpartist;
    tmpSong.setArtist(tmpartist);
    int count=0, length=0;
    bool loop=true;
    do {
        count++;
        cout << "Enter name of the song: " << endl;
        cin >> tmpsong;
        cout << "Enter the songs length in seconds: " << endl;
        cin >> length;
        cout << "Add another song to album " << tmpAlbum << "? (1/0)\n";
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
