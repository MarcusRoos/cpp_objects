//
// Created by Marcus Roos on 2020-02-27.
// Mittuniversitet
// StudentID: Maro1904
//

#include "queue.h"

class Node
{
public: // Declares functions of class Node
    Node *next; // Points to next
    Item data; // Contains an object of the type Person
    // Will assign newData of type Person where *n is pointing at
    Node (Node *n, Item newData) : next(n), data(newData) {}
};

/**
Constructor of QIterator, will initialize node to point to null
*/
QIterator::QIterator(){
    node = nullptr;
}

/**
Use dereference as input, will point node to this pointer
*/
QIterator::QIterator(Node *n){
    node = n;
}

/**
Overloads dereference operator, returns reference to Item pointing to data
*/
Item &QIterator::operator*() const {
    return (Item &) node->data;
}

/**
Overloads operator ++ prefix, will iterate to new node and return it
*/
QIterator &QIterator::operator++() {
    if (!node)
    return *this;
    node = node->next;
    return *this;
}

/**
Overloads operator ++ postfix, will return a node, then  point towards the
 next node
*/
QIterator QIterator::operator++(int) {
    QIterator tmp = *this;
    node = node->next;
    return tmp;
}

/**
Overloads operator !=, will return true if the two objects don't match
*/
bool QIterator::operator!=(const QIterator &qi) const {
    return node != qi.node;
}

/**
QList destructor, will free the place allocated for the lists nodes
*/
QList::~QList() {
    while (!isEmpty()) {
        Node *tmp = first;
        first = first->next;
        delete tmp;
    }
    std::cout << "Destructing...\n";
}

/**
QList enque, will add a new person to the end of the list of the object Item
*/
void QList::enque(Item item) {
    if (isEmpty()) {
        first = last = new Node(nullptr, item);
    }
    else {
        last->next = new Node(nullptr, item);
        last = last->next;
    }
}

/**
QList deque, will remove a person at the start of the list. Will return true or
 false depending if the person is found or not
*/
bool QList::deque(Item &item) {
    if (isEmpty()) {
        return false;
    }
    else {
        Node *n = first;
        first = first->next;
        item = n->data;
        delete n;
        return true;
    }
}

/**
QList delete, will take a parameter in form of Item and use it to determine
 whether the person exists or not. If it does, the person will be deleted
 and "true" will return. Otherwise false will return and nothing will be
 deleted
*/
bool QList::del(Item item) {
    Node *current = first;
    Node *prev = nullptr;
    while (current != nullptr) {
        if (current->data == item) {
            if (current == first) {
                first = current->next;
            } else if (current == last) {
                last = prev;
                prev->next = nullptr;
            } else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
        return false;
}

/**
Checks whether the list is empty or not by checking the very first node,
 if the first node is pointing to null true will return
*/
bool QList::isEmpty() const {
    return first == nullptr;
}