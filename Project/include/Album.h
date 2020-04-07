//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_ALBUM_H
#define DT019G_ALBUM_H
#include "Song.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

class Album {
private:
std::string album;
std::vector<Song>song;
public:
    void setAlbum(std::string palbum);
    void setSong(std::vector<Song> psong);
    void addSong(const Song& psong);
    std::vector<Song> getSong() const;
    std::string getAlbum() const;
    bool operator < (const Album& a) const;
};
std::ostream &operator<<(std::ostream &os, const Album &album);
std::istream &operator>>(std::istream &is, Album &album);

#endif //DT019G_ALBUM_H
