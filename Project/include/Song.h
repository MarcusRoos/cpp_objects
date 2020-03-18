//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_SONG_H
#define DT019G_SONG_H
#include <string>
#include "Time.h"

class Song {
private:
    std::string title;
    std::string artist;
    Time length;
public:
    Song();
    Song(std::string partist, std::string ptitle, Time length);
    void setArtist(std::string partist);
    void setTitle(std::string ptitle);
    std::string getArtist() const;
    std::string getTitle() const;
};
#endif //DT019G_SONG_H
