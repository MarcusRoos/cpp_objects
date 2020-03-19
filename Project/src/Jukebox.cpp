//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Jukebox.h"

void Jukebox::run() {
    menu.addItem("File...", true);
    menu.addItem("Add an album", false);
    menu.addItem("Delete an album", false);
    menu.addItem("Print...", false);
    menu.addItem("Exit", true);
    menu.printMenuItems();

    bool again = true;
    do
    {
        menu.printMenuItems();
        switch(menu.menuChoice())
        {
            case 1:
                file();
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                again = false;
                break;
        }
    }while(again);
}

void Jukebox::file() {

}

void Jukebox::print() {

}
