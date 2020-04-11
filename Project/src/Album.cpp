//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Album.h"
#include <utility>

void Album::setAlbum(std::string palbum) {
    album = std::move(palbum);
}
/*
void Album::setSong(std::vector<Song> psong) {
    song = std::move(psong);
}*/

void Album::addSong(const Song& psong){
    song.push_back(psong);
}

std::string Album::getAlbum() const {
    return album;
}

std::vector<Song> Album::getSong() const {
    return song;
}

bool Album::operator<(const Album &a) const {
    int tmpE=0, tmpA=0;
    for (auto &e : song){
        tmpE += e.getLength();
    }
    for (auto &p : a.getSong()){
        tmpA += p.getLength();
    }
    return tmpA < tmpE;
}

std::ostream &operator<<(std::ostream &os, const Album &album){
    int amount=0, i=0;
    bool test=true;
        for (auto &e : album.getSong()) {
            amount++;
        }
        os << album.getAlbum() << '\n';
        if (amount>0) {
            os << amount << '\n';
        }
        for (auto &p : album.getSong()) {
            os << p.getTitle() << '|' << p.getArtist() << '|'
               << p.getLength();
            i++;
            if (i == amount+1)
                test = false;
            if (test) {
                os << "\n";
            }
        }
    return os;
}

/** Defines operator >>, used for in stream, will go through string until
 * it finds deliminator, will then set the class object and keep searching the
 * string. **/
std::istream &operator>>(std::istream &is, Album &album){
    std::string tmpString;
    Song tmpSong;
    int amount=0;
    getline(is,tmpString,'\n');
    album.setAlbum(tmpString);
    is >> amount;
    getline(is,tmpString,'\n');
    for(int i=0; i<amount; i++) {
        int tmpInt = 0;
        getline(is, tmpString, '|');
        tmpSong.setTitle(tmpString);
        getline(is, tmpString, '|');
        tmpSong.setArtist(tmpString);
        is >> tmpInt;
        is.get();
        tmpSong.setLength(tmpInt);
        album.addSong(tmpSong);
    }
    return is;
}

