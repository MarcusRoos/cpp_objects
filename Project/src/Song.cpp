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
    while (ptitle>3600){
        int i=0;
        i++;
        length.setHour(i);
        ptitle = ptitle-3600;
    }
    while (ptitle>60){
        int i=0;
        i++;
        length.setMin(i);
        ptitle = ptitle-60;
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
    return length.getHour() && length.getMin() && length.getSec();
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

