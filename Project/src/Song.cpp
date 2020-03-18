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
}

// Initilizing constructor
Song::Song(std::string partist, std::string ptitle, Time plength)
{
    artist = std::move(partist);
    title = std::move(ptitle);
    length = plength;
}

void Song::setTitle(std::string ptitle)
{
    title = std::move(ptitle);
}

// Sets last name
void Song::setArtist(std::string partist)
{
    artist = std::move(partist);
}

// Gets first name
std::string Song::getTitle() const
{
    return title;
}

// Gets last name
std::string Song::getArtist() const
{
    return artist;
}