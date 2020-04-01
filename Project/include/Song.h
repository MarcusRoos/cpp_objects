//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_SONG_H
#define DT019G_SONG_H
#include <string>
#include "Length.h"

class Song {
private:
    std::string title;
    std::string artist;
    Length length;
public:
    Song();
    Song(std::string partist, std::string ptitle, Length length);
    void setArtist(std::string partist);
    void setTitle(std::string ptitle);
    void setLength(int plength);
    std::string getArtist() const;
    std::string getTitle() const;
    int getLength() const;
    int getHour() const;
    int getMin() const;
    int getSec() const;
};
#endif //DT019G_SONG_H
