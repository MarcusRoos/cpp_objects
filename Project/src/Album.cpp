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

void Album::setSong(std::vector<Song> psong) {
    song = std::move(psong);
}

void Album::addSong(const Song& psong){
    song.push_back(psong);
}

std::string Album::getAlbum() const {
    return album;
}

std::vector<Song> Album::getSong() const {
    return song;
}

bool Album::operator<(const Song &a) const {
    return a.getLength() < a.getLength();
}

std::ostream &operator<<(std::ostream &os, const Album &album){
    os << album.getAlbum();
    for (auto &e : album.getSong()) {
        os << e.getTitle();
        os << e.getArtist();
        os << e.getLength();
    }
    return os;
}

/** Defines operator >>, used for in stream, will go through string until
 * it finds a '|', will then set the class object and keep searching the
 * string. **/
std::istream &operator>>(std::istream &is, Album &album){
    std::string tmpString;
    int amount=0;
    getline(is,tmpString,'\n');
    album.setAlbum(tmpString);
    getline(is,tmpString,'\n');
    is >> amount;
    for (int i=0; i<amount; i++){
        for (auto &e : album.getSong()){
            getline(is,tmpString,'|');
            e.setTitle(tmpString);
            getline(is,tmpString,'|');
            e.setArtist(tmpString);
            getline(is,tmpString,'|');
            int tmpInt;
            is >> tmpInt;
            is.get();
            e.setLength(tmpInt);
        }
    }

    return is;
}