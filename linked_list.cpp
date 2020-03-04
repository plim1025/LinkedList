#include "linked_list.h"
#include "node.h"
#include <iostream>

Linked_List::Linked_List():length(0), head(nullptr), tail(nullptr) {

}

Linked_List::~Linked_List() {
    Node *node_ptr = head;
    for(node_ptr = head; node_ptr != NULL; node_ptr=node_ptr->next)
        delete node_ptr;
}

int Linked_List::get_length() {
    return length;
}

void Linked_List::print() {
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
    tail = nullptr;
    length = 0;
}

unsigned int Linked_List::push_front(int val) {
    Node *node = new Node(val);
    if(head == nullptr) {
        node->next = nullptr;
        tail = node;
    } else {
        node->next = head;
    }
    head = node;
    length++;
    return length;
}

unsigned int Linked_List::push_back(int val) {
    Node *node = new Node(val);
    if(head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
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
    if(head == nullptr) {
        head = node;
        tail = node;
    }
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
        if(index == length)
            tail = node;
    }
    length++;
    return length;
}

void sort_ascending() {

}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}