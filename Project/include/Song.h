//
// Created by Marcus Roos on 2020-03-16.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_SONG_H
#define DT019G_SONG_H
#include <string>
#include "Length.h"
#include <iostream>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Song

 Keeps track of the songs of an album
 Contain members title and artist as type string, and songs length of type Length
 Several different public member functions used to either set, get or add a song
 as well as getting either length of type Length, or individual members using
 getHour/getMin/getSec functions.
Regarding the "getHour/getMin/getSec" functions I included a description as to
 why I decided to add them, and how I would go about if they are not allowed, in
 the ReadMe file.
 */
class Song {
private:
    std::string title;
    std::string artist;
    Length length;
public:
    /**
* Default constructor of class Song
*
* @param None.
* @return None.
*/
    Song();

    /**
* Constructor for initialization of class Song
*
* @param string partist, ptitle and length of type Length
* @return None.
*/
    Song(std::string partist, std::string ptitle, Length length);

    /**
* Sets value for class member artist
*
* @param string partist
* @return None.
*/
    void setArtist(std::string partist);

    /**
* Sets value for class member title
*
* @param string ptitle
* @return None.
*/
    void setTitle(std::string ptitle);

    /**
* Sets value for class member length
*
* @param plength of type Length
* @return None.
*/
    void setLength(int plength);

    /**
* Returns value for class member artist, constant
* Inline
* @param None.
* @return artist.
*/
    std::string getArtist() const { return artist; }

    /**
* Returns value for class member title, constant
* Inline
* @param None.
* @return title.
*/
    std::string getTitle() const { return title; }

    /**
* Returns value for class member length, constant
*
* @param None.
* @return Converted form of length, type int.
*/
    int getLength() const;

    /**
* Returns values from class member Length, constant
* Inline
* @param None.
* @return Returns hour, min and sec from the class Length.
*/
    int getHour() const;
    int getMin() const;
    int getSec() const;
};

/**
* Overloads operator << ( out stream )
*
* @param Constant reference of class Song, out stream os.
* @return os.
*/
std::ostream &operator<<(std::ostream &os, const Song &song);

/**
* Overloads operator >> ( in stream )
*
* @param Constant reference of class Song, in stream is.
* @return is.
*/
std::istream &operator>>(std::istream &is, Song &song);
#endif //DT019G_SONG_H
