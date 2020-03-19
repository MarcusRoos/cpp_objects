//
// Created by Marcus Roos on 2020-03-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_MENUITEM_H
#define DT019G_MENUITEM_H
#include <string>
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
