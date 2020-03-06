#include "node.h"
#include "linked_list.h"
#include <iostream>

int main() {
    Linked_List linked_list;
    linked_list.insert(4, 0);
    linked_list.insert(5, 0);
    linked_list.insert(3, 0);
    linked_list.insert(2, 0);
    linked_list.insert(1, 0);
    linked_list.insert(0, 0);

    linked_list.print();
    linked_list.mergeSort(0, 5);
    linked_list.print();
    // linked_list.swap_nodes(0, 1);
    // linked_list.print();
    // linked_list.swap_nodes(1, 3);
    // linked_list.print();
    return 0;
}