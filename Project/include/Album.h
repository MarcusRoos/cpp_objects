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
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Album

 Keeps track of albums.
 Contain members album as type string, as song of custom type Song.
 Several different public member functions used to either set, get or add a song
 as well as overloading the less than operator which will compare the length of
 a song to another.
 */
class Album {
private:
std::string album;
std::vector<Song>song;
public:
    /**
* Sets member album
*
* @param string.
* @return None.
*/
    void setAlbum(std::string palbum);

    /* I never used the function setsong, I stuck to the addSong function
     Without a "play" menu I didn't see the purpose of the setsong function
     I could have used it while adding a new album, simply creating a
     temporary vector an pushing thew newly added songs to it, and finally
     using the setSong function to push it to a specific album but I did not
     see the need to do this. */
    /**
* Sets member song
*
* @param vector container of type Song.
* @return None.
*/
//    void setSong(std::vector<Song> psong);

    /**
* Adds a single song to the vector song
*
* @param constant reference of the type song.
* @return None.
*/
    void addSong(const Song& psong);

    /**
* Gets a song
*
* @param None
* @return A vector of type Song, constant.
*/
    std::vector<Song> getSong() const;

    /**
* Gets album
*
* @param None
* @return A string, constant.
*/
    std::string getAlbum() const;

    /**
* Overloads operator < ( less than )
*
* @param Constant reference of class Album.
* @return true or false.
*/
    bool operator < (const Album& a) const;
};

/**
* Overloads operator << ( out stream )
*
* @param Constant reference of class Album, out stream os.
* @return os.
*/
std::ostream &operator<<(std::ostream &os, const Album &album);

/**
* Overloads operator << ( in stream )
*
* @param Constant reference of class Album, in stream in.
* @return in.
*/
std::istream &operator>>(std::istream &is, Album &album);

#endif //DT019G_ALBUM_H
