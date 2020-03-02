#include "linked_list.h"

Linked_List::Linked_List():length(0), head(nullptr) {

}

Linked_List::Linked_List(int length, Node *head):length(length), head(head) {

}

int Linked_List::get_length() {
    return length;
}