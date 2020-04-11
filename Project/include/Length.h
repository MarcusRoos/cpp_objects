#ifndef DT019G_LENGTH_H
#define DT019G_LENGTH_H
#include <iostream>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Length

 Keeps track of the length of an item.
 Contain members hour, min and sec as type int.
 Several different public member functions used to either set, get or add a length
 as well as overloading the less than, equals to and plus operator.
 */
class Length {
private:
    int hour, min, sec;

public:
    /**
* Default constructor of class Length
*
* @param None.
* @return None.
*/
    Length();

    /**
* Constructor for initialization of class Length
*
* @param int pHour, pMin, pSec.
* @return None.
*/
    Length(int pHour, int pMin=0, int pSec=0);
    /**
* Destructor for class Length
*
* @param None.
* @return None.
*/
    ~Length()=default;

    /**
* Sets value for class member hour
*
* @param int pHour
* @return None.
*/
    void setHour(int pHour);

    /**
* Sets value for class member min
*
* @param int pMin
* @return None.
*/
    void setMin(int pMin);

    /**
* Sets value for class member sec
*
* @param int pSec
* @return None.
*/
    void setSec(int pSec);

    /**
* Returns value for class member hour, constant
* Inline
* @param None.
* @return hour.
*/
    int getHour() const { return hour; }

    /**
* Returns value for class member min, constant
* Inline
* @param None.
* @return min.
*/
    int getMin() const { return min; }

    /**
* Returns value for class member sec, constant
* Inline
* @param None.
* @return sec.
*/
    int getSec() const { return sec; }

    /**
* Overloads operator == ( comparison )
*
* @param Constant reference of class Length.
* @return True or false.
*/
    bool operator == (const Length& a) const;

    /**
* Overloads operator + ( addition )
*
* @param Constant reference of class Length.
* @return Length
*/
    Length operator + (const Length& a) const;

    /**
* Overloads operator < ( less than )
*
* @param Constant reference of class Length.
* @return True or false.
*/
    bool operator < (const Length& a) const;
};

/**
* Overloads operator << ( out stream )
*
* @param Constant reference of class Length, out stream os.
* @return os.
*/
std::ostream &operator<<(std::ostream &os, const Length &length);

/**
* Overloads operator >> ( in stream )
*
* @param Constant reference of class Length, in stream is.
* @return is.
*/
std::istream &operator>>(std::istream &is, const Length &length);
#endif //DT019G_LENGTH_H
