/*
** Program: Linked Lists
** Author: Paul Lim
** Date: 3/7/2020
** Description: A program that appends integers to the end of a linked list, sorts them, and prints out number of prime numbers
*/

#include "node.h"
#include "linked_list.h"
#include <iostream>

void store_nums(Linked_List&);
void sort_nums(Linked_List&);

// Driver Function
int main() {
    Linked_List linked_list;
    std::string again = "y";
    while(again == "y") {
        store_nums(linked_list);
        sort_nums(linked_list);
        linked_list.print();
        std::cout << "You have " << linked_list.prime_nums(linked_list) << " prime number(s) in your list." << std::endl;
        again = "";
        while(again != "y" && again != "n") {
            std::cout << "Do you want to do this again (y or n)? ";
            std::getline(std::cin, again);
        }
        linked_list.clear();
    }
    return 0;
}

// Get numbers from user and store in linked list
void store_nums(Linked_List& list) {
    std::string another_num = "y";
    while(another_num == "y") {
        int num = 0;
        std::cout << "Please enter a number: ";
        std::cin >> num;
        std::cin.ignore();
        list.push_front(num);
        do {
            std::cout << "Do you want another num (y or n): ";
            std::getline(std::cin, another_num);
        } while(another_num != "y" && another_num != "n");
    }
}

// Gets method to sort linked list from user and sorts
void sort_nums(Linked_List& list) {
    std::string sort_mode = "";
    while(sort_mode != "a" && sort_mode != "d") {
            std::cout << "Sort ascending or descending (a or d)? ";
            std::getline(std::cin, sort_mode);
        }
    if(sort_mode == "a")
        list.sort_ascending();
    else
        list.sort_descending();
}