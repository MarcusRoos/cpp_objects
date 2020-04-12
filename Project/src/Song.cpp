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

// Sets title
void Song::setTitle(std::string ptitle)
{
    title = std::move(ptitle);
}

// Sets artist
void Song::setArtist(std::string partist)
{
    artist = std::move(partist);
}

// Sets length
void Song::setLength(int ptitle) {
    int i=1;
    length.setHour(0);
    length.setMin(0);
    length.setSec(0);
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

// Gets length, using above operators to return a single integer
int Song::getLength() const {
    return length.getHour()*3600 + length.getMin()*60 + length.getSec();
}

// Gets hour
int Song::getHour() const {
    return length.getHour();
}

// Gets min
int Song::getMin() const {
    return length.getMin();
}

// Gets sec
int Song::getSec() const {
    return length.getSec();
}

// Defines operator <<, used for out stream
std::ostream &operator<<(std::ostream &os, const Song &song){
    os << song.getTitle() << '|' << song.getArtist() << '|' << song.getLength();
    return os;
}

// Defines operator >>, used for in stream
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
