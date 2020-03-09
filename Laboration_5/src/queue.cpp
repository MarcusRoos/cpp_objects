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

QIterator::QIterator(){
    node = nullptr;
}

QIterator::QIterator(Node *n){
    node = n;
}

Item &QIterator::operator*() const {
    return (Item &) node->data;
}

QIterator &QIterator::operator++() {
    if (!node)
    return *this;
    node = node->next;
    return *this;
}

QIterator QIterator::operator++(int) {
    QIterator tmp = *this;
    node = node->next;
    return tmp;
}

bool QIterator::operator!=(const QIterator &qi) const {
    return *this != qi;
}

QList::~QList() {
    while (!isEmpty()) {
        Node *tmp = first;
        first = first->next;
        delete tmp;
    }
    std::cout << "Destructing...\n";
}

void QList::enque(Item item) {
    if (isEmpty()) {
        first = last = new Node(nullptr, item);
    }
    else {
        last->next = new Node(nullptr, item);
        last = last->next;
    }
}

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

bool QList::isEmpty() const {
    return first == nullptr;
}