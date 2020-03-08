#include "linked_list.h"
#include "node.h"
#include <iostream>

// Linked_List constructor
Linked_List::Linked_List():length(0), head(nullptr) {

}

// Linked_List destructor
Linked_List::~Linked_List() {
    Node *node_ptr = head;
    for(node_ptr = head; node_ptr != NULL; node_ptr=node_ptr->next)
        delete node_ptr;
}

// Returns length of Linked_List
int Linked_List::get_length() const {
    return length;
}

// Prints out Linked_List
void Linked_List::print() const {
    std::cout << "Your linked list is: ";
    if(length > 0) {
        Node *node_ptr = head;
        for(node_ptr = head; node_ptr != NULL; node_ptr=node_ptr->next)
            std::cout << node_ptr->val << " ";
        std::cout << std::endl;
    }
    else
        std::cout << "List is empty" << std::endl;
}

// Clears Linked_List of all nodes so that it is empty
void Linked_List::clear() {
    Node *node_ptr = head;
    for(node_ptr = head; node_ptr != NULL; node_ptr=node_ptr->next)
        delete node_ptr;
    head = nullptr;
    length = 0;
}

// Adds integer to front of Linked_List
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

// Adds integer to back of Linked_List
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

// Inserts integer at given index of Linked_List
unsigned int Linked_List::insert(int val, unsigned int index) {
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

// Added functionality to index Linked_List using []
int Linked_List::operator[](int index) {
    Node *node_ptr = head;
    for(int i = 0; i < index; i++)
        node_ptr = node_ptr->next;
    return node_ptr->val;
}

// Returns pointer to node_ptr
Node** Linked_List::get_node_ptr(int index) {
    Node **node_ptr = &head;
    for(int i = 0; i < index; i++)
        node_ptr = &((*node_ptr)->next);
    return node_ptr;
}

// Swaps two Node pointers
void Linked_List::swap_node_pointers(Node *&a, Node *&b) {
    Node *t = a;
    a = b;
    b = t;
}

// Swaps two Nodes of given indexes
void Linked_List::swap_nodes(int indexA, int indexB) {
    if(indexA == indexB)
        return;
    Node **a = get_node_ptr(indexA);
    Node **b = get_node_ptr(indexB);
    swap_node_pointers(*a, *b);
    swap_node_pointers((*a)->next, (*b)->next);
}

// Merges given indexes of a list
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
    mergeWhiles(i, n1, j, n2, L, R, k);
}

// Swaps values of list
void Linked_List::mergeWhiles(int i, int n1, int j, int n2, int *L, int *R, int k) {
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            (*get_node_ptr(k))->val = L[i];
            i++;
        } else {
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

// Parent merge function to sort list ascending
void Linked_List::mergeSort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        merge(*this, left, middle, right);
    }
}

// Returns max index of given list within indexes
int Linked_List::maxIndex(Linked_List &list, int i, int j) {
    if(i == j)
        return i;
    int k = maxIndex(list, i + 1, j);
    return (list[i] > list[k]) ? i : k;
}

// Parent function to sort list descending
void Linked_List::selectionSort(int n, int index = 0) {
    if(index == n)
        return;
    int k = maxIndex(*this, index, n - 1);
    if(k != index)
        swap_nodes(k, index);
    selectionSort(n, index + 1);
}

// Sorts list ascending with merge sort
void Linked_List::sort_ascending() {
    mergeSort(0, length - 1);
}

// Sorts list descending with selection sort
void Linked_List::sort_descending() {
    selectionSort(length);
}

// Returns number of prime numbers in list
int Linked_List::prime_nums(Linked_List& list) {
    int num_primes = 0;
    for(int i = 0; i < length; i++)
        if(is_prime(list[i]))
            num_primes++;
    return num_primes;
}

// Determines if given integer is prime or not
bool Linked_List::is_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}