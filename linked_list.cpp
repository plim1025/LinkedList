#include "linked_list.h"
#include "node.h"
#include <iostream>

Linked_List::Linked_List():length(0), head(nullptr) {

}

Linked_List::~Linked_List() {

}

int Linked_List::get_length() {
    return length;
}

void Linked_List::print() {
    Node *node_ptr = head;
    for(int i = 0; i < length; i++) {
        std::cout << node_ptr->val << " " << node_ptr << " ";
        node_ptr = node_ptr->next;
    }
    std::cout << std::endl;
}

unsigned int Linked_List::push_front(int val) {
    Node new_node(val, head);
    if(length > 0)
        std::cout << new_node.next->val << " " << new_node.val << std::endl;
    head = &new_node;
    std::cout << head->val << std::endl;
    length++;
    return length;
}

unsigned int Linked_List::push_back(int val) {

    length++;
    return length;
}