#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class Linked_List {
private:
    unsigned int length;
    Node *head;

public:
    Linked_List();
    ~Linked_List();

    int get_length();
    void print();
    void clear();
    unsigned int push_front(int);
    unsigned int push_back(int);
    unsigned int insert(int val, unsigned int index);
    void sort_ascending();
    void sort_descending();
    void num_primes();
};

#endif