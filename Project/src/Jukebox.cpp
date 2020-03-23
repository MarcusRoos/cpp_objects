//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Jukebox.h"
#include <iostream>

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
                std::cout << "Add - Disabled\n";
                break;
            case 3:
                std::cout << "Delete - Disabled\n";
                break;
            case 4:
                std::cout << "Print - Disabled\n";
                break;
            case 5:
                std::cout << "Exit\n";
                again = false;
                break;
        }
    }while(again);
}

void Jukebox::file() {
    std::cout <<"**** FILE ****\n";
    std::cout <<"1. Open\n";
    std::cout <<"2. Save\n";
    std::cout <<"3. Back to main menu\n";
}

void Jukebox::print() {
    std::cout <<"**** PRINT ****\n";
    std::cout <<"1. Print one album\n";
    std::cout <<"2. Print all sorted by album name\n";
    std::cout <<"3. Print all sorted by album total time\n";
    std::cout <<"4. Print simple sorted by album name\n";
    std::cout <<"5. Print simple sroted by album total time\n";
    std::cout <<"6. Back to main menu\n";
}

Jukebox::Jukebox() {
    menu.setTitle("Title menu");
    filemenu.setTitle("File menu");
    menu.addItem("File...", true);
    menu.addItem("Add an album", false);
    menu.addItem("Delete an album", false);
    printmenu.setTitle("Print menu");
    menu.addItem("Print...", false);
    menu.addItem("Exit", true);
}
