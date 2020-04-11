//
// Created by Marcus Roos on 2020-03-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_MENUITEM_H
#define DT019G_MENUITEM_H
#include <string>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class MenuItem

 Keeps track of whether a menu is enabled or not, as well as the text of menu.
 Contain members album as type string, as song of custom type Song.
 Several different public member functions used to either set, get or add a song
 as well as overloading the less than operator which will compare the length of
 a song to another.
 */
class MenuItem {
private:
std::string menutext;
bool enabler;
public:
    MenuItem();
    MenuItem(std::string pmenutext, bool penabler);
    ~MenuItem()=default;
    void setMenuText(std::string pmenutext);
    void setEnabled(bool penabler);
    std::string getMenuText() const;
    bool getEnabled() const;
};
#endif //DT019G_MENUITEM_H
