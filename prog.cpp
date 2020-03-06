#include "node.h"
#include "linked_list.h"
#include <iostream>

int main() {
    Linked_List linked_list;
    linked_list.push_front(1);
    linked_list.push_front(3);
    linked_list.push_front(2);
    linked_list.push_front(61);
    linked_list.push_front(76);
    linked_list.push_front(3);
    linked_list.push_front(1);
    linked_list.push_front(4);
    linked_list.sort_descending();
    linked_list.print();
    // linked_list.swap_nodes(0, 1);
    // linked_list.print();
    // linked_list.swap_nodes(1, 3);
    // linked_list.print();
    return 0;
}