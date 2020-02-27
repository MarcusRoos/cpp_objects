//
// Created by Marcus Roos on 2020-02-27.
// Mittuniversitet
// StudentID: Maro1904
//

#include "queue.h"

class Node
{
public:
    Node *next;
    Item data;
    Node (Node *n, Item newData) : next(n), data(newData) {}
};

/*
bool operator != (const Person& a, const Person& b)
{
    return !(a==b);
}
 */