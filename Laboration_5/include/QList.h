//
// Created by Marcus Roos on 2020-02-25.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_QLIST_H
#define DT019G_QLIST_H

class Node; // Forward declaration
class QList
{
private:
Node *first;
Node *search(int searchItem) const;
public:
List();
~List();
void putFirst(int d); void putLast(int d);
void insAfter(int searchItem, int d); void showList() const;
bool searchFor(int searchItem) const;
};

#endif //DT019G_QLIST_H
