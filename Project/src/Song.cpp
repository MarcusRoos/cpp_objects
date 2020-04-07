//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Song.h"

// Default constructor
Song::Song()
{
    artist = "";
    title = "";
    length = Length(0, 0, 0);
}

// Initilizing constructor
Song::Song(std::string partist, std::string ptitle, Length plength)
{
    artist = std::move(partist);
    title = std::move(ptitle);
    length = Length(plength);
}

void Song::setTitle(std::string ptitle)
{
    title = std::move(ptitle);
}

// Sets artist
void Song::setArtist(std::string partist)
{
    artist = std::move(partist);
}

void Song::setLength(int ptitle) {
    int i=1;
    while (ptitle>=3600){
        length.setHour(i);
        ptitle = ptitle-3600;
        i++;
    }
    i=1;
    while (ptitle>=60){
        length.setMin(i);
        ptitle = ptitle-60;
        i++;
    }
    length.setSec(ptitle);
}

// Gets title
std::string Song::getTitle() const
{
    return title;
}

// Gets artist
std::string Song::getArtist() const
{
    return artist;
}

int Song::getLength() const {
    return length.getHour() + length.getMin() + length.getSec();
}

int Song::getHour() const {
    return length.getHour();
}

int Song::getMin() const {
    return length.getMin();
}

int Song::getSec() const {
    return length.getSec();
}

std::ostream &operator<<(std::ostream &os, const Song &song){
    os << song.getTitle() << '|' << song.getArtist() << '|' << song.getLength();
    return os;
}

/** Defines operator >>, used for in stream, will go through string until
 * it finds a '|', will then set the class object and keep searching the
 * string. **/
std::istream &operator>>(std::istream &is, Song &song){
    std::string tmpString;
    getline(is,tmpString,'|');
    song.setTitle(tmpString);
    getline(is,tmpString,'|');
    song.setArtist(tmpString);
    int tmpInt=0;
    is >> tmpInt;
    song.setLength(tmpInt);
    return is;
}
