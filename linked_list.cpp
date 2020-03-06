#include "linked_list.h"
#include "node.h"
#include <iostream>

Linked_List::Linked_List():length(0), head(nullptr) {

}

Linked_List::~Linked_List() {
    Node *node_ptr = head;
    for(node_ptr = head; node_ptr != NULL; node_ptr=node_ptr->next)
        delete node_ptr;
}

int Linked_List::get_length() const {
    return length;
}

void Linked_List::print() const {
    if(length > 0) {
        Node *node_ptr = head;
        for(node_ptr = head; node_ptr != NULL; node_ptr=node_ptr->next)
            std::cout << node_ptr->val << " ";
        std::cout << std::endl;
    }
    else
        std::cout << "List is empty" << std::endl;
}

void Linked_List::clear() {
    Node *node_ptr = head;
    for(node_ptr = head; node_ptr != NULL; node_ptr=node_ptr->next)
        delete node_ptr;
    head = nullptr;
    length = 0;
}

unsigned int Linked_List::push_front(int val) {
    Node *node = new Node(val);
    if(head == nullptr) {
        node->next = nullptr;
    } else {
        node->next = head;
    }
    head = node;
    length++;
    return length;
}

unsigned int Linked_List::push_back(int val) {
    Node *node = new Node(val);
    if(head == nullptr)
        head = node;
    else {
        Node* tail_ptr = *(get_node_ptr(length - 1));
        tail_ptr->next = node;
    }
    length++;
    return length;
}

unsigned int Linked_List::insert(int val, unsigned int index) {
    if(index > length || index < 0) {
        std::cout << "Invalid index in insert function of linked list" << std::endl;
        return length;
    }
    Node *node = new Node(val);
    if(head == nullptr)
        head = node;
    else if(index == 0) {
        node->next = head;
        head = node;
    }
    else {
        Node *before = head;
        for(int i = 0; i < index - 1; i++)
            before = before->next;
        Node *after = before->next;
        node->next = after;
        before->next = node;
    }
    length++;
    return length;
}

int Linked_List::operator[](int index) {
    Node *node_ptr = head;
    for(int i = 0; i < index; i++)
        node_ptr = node_ptr->next;
    return node_ptr->val;
}

Node** Linked_List::get_node_ptr(int index) {
    Node **node_ptr = &head;
    for(int i = 0; i < index; i++)
        node_ptr = &((*node_ptr)->next);
    return node_ptr;
}

void Linked_List::swap_node_pointers(Node *&a, Node *&b) {
    Node *t = a;
    a = b;
    b = t;
}

void Linked_List::swap_nodes(int indexA, int indexB) {
    if(indexA == indexB)
        return;
    Node **a = get_node_ptr(indexA);
    Node **b = get_node_ptr(indexB);
    swap_node_pointers(*a, *b);
    swap_node_pointers((*a)->next, (*b)->next);
}

void Linked_List::merge(Linked_List& list, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = list[l + i];
    for (j = 0; j < n2; j++)
        R[j] = list[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            (*get_node_ptr(k))->val = L[i];
            i++;
        }
        else {
            (*get_node_ptr(k))->val = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        (*get_node_ptr(k))->val = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        (*get_node_ptr(k))->val = R[j];
        j++;
        k++;
    }
}

void Linked_List::mergeSort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        merge(*this, left, middle, right);
    }
}

void Linked_List::sort_ascending() {
    mergeSort(0, length - 1);
}