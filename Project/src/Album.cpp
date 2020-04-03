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