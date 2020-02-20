//
// Created by Marcus Roos on 2020-02-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_ARRAYSORT_H
#define DT019G_ARRAYSORT_H

#include <cstdlib>
#include <iomanip>
#include <iostream>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class ArraySort

Stores an array which will be used to test out the efficiency of different
 sorting methods. The size of the array is dynamically created, as well as
 dynamically filled with elements.
 */
class ArraySort
{
private: // Class members
    int* arr; // Pointer for array
    size_t maxSize; // Max Size of array
    size_t size; // Size of array
public: // Class functions

    /**
    * Default constructor of the class ArraySort
    *
    * @param None.
    * @return None.
    */
    ArraySort();

    /**
    * Constructor, Sets size of the array
    *
    * @param String pStreet, pPostcode, pCity.
    * @return None.
    */
    ArraySort (int pNum);

    /**
    * Constructor of the class ArraySort
    *
    * @param Const of class arraysort reference.
    * @return None.
    */
    ArraySort( const ArraySort &a);

    /**
    * Destructor of the class ArraySort
    *
    * @param None.
    * @return None.
    */
    ~ArraySort();

    /**
    * Adds value to the array within the class
    *
    * @param integer.
    * @return true/False.
    */
    bool addValue(int value);

    /**
    * Sets size of array
    *
    * @param integer.
    * @return None.
    */
    void setSize(int pSize);

    /**
    * Sorting algorithm
    *
    * @param integer.
    * @return None.
    */
    void bubbleSort1(int n);

    /**
    * Sorting algorithm
    *
    * @param integer.
    * @return None.
    */
    void selectSort(int n);

    /**
    * Sorting algorithm
    *
    * @param integer.
    * @return None.
    */
    void insertSort(int n);

    /**
    * Sorting algorithm
    *
    * @param integer.
    * @return None.
    */
    void q1(int n);


}; // End of class ArraySort definition


#endif //DT019G_ARRAYSORT_H
