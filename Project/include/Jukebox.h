//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_JUKEBOX_H
#define DT019G_JUKEBOX_H
#include "Menu.h"
#include "Management.h"
class Jukebox {
private:
    Menu menu, filemenu, printmenu;
    void file();
    void print();
public:
    Jukebox();
    void run();
};
#endif //DT019G_JUKEBOX_H
