#include "node.h"

Node::Node():val(0), next(nullptr) {

}

Node::Node(int val):val(val), next(nullptr) {

}

Node::Node(int val, Node *next):val(val), next(next) {

}

Node::~Node() {

}