#ifndef NODE_H
#define NODE_H

class Node {
public:
    int val;
    Node *next;

    Node();
    Node(int);
    Node(int, Node*);
    ~Node();
};

#endif
