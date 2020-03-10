//
// Created by Marcus Roos on 2020-02-27.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_QUEUE_H
#define DT019G_QUEUE_H

#include "Person.h"

typedef Person Item;
class Node;
class QIterator{
private:
    Node *node;
public:
    /**
* Constructor of the class QIterator
* Default constructor
* @param None.
* @return None.
*/
    QIterator();
    /**
* Constructor of the class QList
* Initializing constructor
* @param None.
* @return None.
*/
    QIterator(Node *n);
    /**
* Overloads the operator *
*
* @param None.
* @return Reference to an object of type Item.
*/
    Item &operator*() const;
    /**
* Overloads the operator ++ (prefix)
* Increases counter by 1 before action is done
* @param None.
* @return None.
*/
    QIterator &operator++();
    /**
* Overloads the operator ++ (postfix)
* Increases counter by 1 after action is done
* @param Integer.
* @return None.
*/
    QIterator operator++(int);
    /**
* Overloads the operator !=
* Returns true if both objects arent matching
* @param Constant reference to QIterator
* @return True/False
*/
    bool operator!=(const QIterator &qi) const;
};

// Declares class QList
class QList{
private: // Private member functions, pointers to first and last
    Node *first, *last;
public:
    /**
* Constructor of the class QList
* Sets first and last both to point on null
* @param None.
* @return None.
*/
    QList():first(nullptr),last(nullptr){};
    /**
* Deconstructor of class QList
*
* @param None.
* @return None.
*/
    ~QList();
    /**
* Queues an item at the end of the queue
*
* @param Item item (Person).
* @return None.
*/
    void enque(Item item);
    /**
* Deque an item at the start of the queue
*
* @param Item (reference) &item (Person).
* @return None.
*/
    bool deque(Item &item);
    /**
* Deletes an item in the queue, use social security number to find a match
*
* @param Item item (Person).
* @return True/False.
*/
    bool del(Item item);
    /**
* Checks if the queue is empty or not
*
* @param Item item (Person).
* @return True/False.
*/
    bool isEmpty()const;
    /**
* QIterator begin and end, used to iterate through the queue
*
* @param None
* @return QIterator first or nullptr.
*/
    QIterator begin()const {return QIterator(first);}
    QIterator end() const { return QIterator(nullptr);}
}; // End of class QList


#endif //DT019G_QUEUE_H
