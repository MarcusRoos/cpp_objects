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
    QIterator();
    QIterator(Node *n);
    Item &operator*() const;
    QIterator &operator++();
    QIterator operator++(int);
    bool operator!=(const QIterator &qi) const;
};

class QList{
private:
    Node *first, *last;
public:
    QList():first(nullptr),last(nullptr){};
    ~QList();
    void enque(Item item);
    bool deque(Item &item);
    bool del(Item item);
    bool isEmpty()const;
    QIterator begin()const {return QIterator(first);}
    QIterator end() const { return QIterator(nullptr);}
};


#endif //DT019G_QUEUE_H
