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

bool Album::operator<(const Album &a) const {
    return false;
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
 * it finds deliminator, will then set the class object and keep searching the
 * string. **/
std::istream &operator>>(std::istream &is, Album &album){
    std::string tmpString;
    Song tmpSong;
    int amount=0, i=0;
    getline(is,tmpString,'\n');
    album.setAlbum(tmpString);
    std::cout << "Get Album " << album.getAlbum() << std::endl;
    is >> amount;
    std::cout << "AMOUNT " << amount << std::endl;
    getline(is,tmpString,'\n');
    while (i<amount) {
        int tmpInt=0;
        getline(is, tmpString, '|');
        tmpSong.setTitle(tmpString);
        std::cout << "Get Title " << tmpSong.getTitle() << std::endl;
        getline(is, tmpString, '|');
        tmpSong.setArtist(tmpString);
        std::cout << "Get Artist " << tmpSong.getArtist() << std::endl;
        is >> tmpInt;
        is.get();
        tmpSong.setLength(tmpInt);
        std::cout << "H: " << tmpSong.getHour();
        std::cout << " M: " << tmpSong.getMin();
        std::cout << " S" << tmpSong.getSec() << std::endl;
        i++;
    }
    return is;
}