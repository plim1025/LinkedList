#include "node.h"
#include "linked_list.h"
#include <iostream>

int main() {
    Linked_List linked_list;
    linked_list.insert(5, 0);
    linked_list.insert(6, 0);
    linked_list.insert(7, 0);
    linked_list.insert(8, 0);
    linked_list.insert(9, 0);
    linked_list.insert(10, 0);
    linked_list.insert(11, 0);
    linked_list.insert(4, 7);
    linked_list.print();
    return 0;
}