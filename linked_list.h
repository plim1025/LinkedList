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

    int get_length() const;
    void print() const;
    void clear();
    unsigned int push_front(int);
    unsigned int push_back(int);
    unsigned int insert(int, unsigned int);
    Node** get_node_ptr(int);
    int operator[](int);
    void swap_node_pointers(Node *&, Node *&);
    void swap_nodes(int, int);
    void sort_ascending();
    void sort_descending();
    void num_primes();
    void merge(Linked_List&, int, int, int);
    void mergeSort(int, int);
};

#endif