#include "node.h"
#include "linked_list.h"
#include <iostream>

int main() {
    Linked_List linked_list;

    std::string again = "y";
    while(again == "y") {

        std::string another_num = "y";
        while(another_num == "y") {
            int num = 0;
            std::cout << "Please enter a number: ";
            std::cin >> num;
            linked_list.push_front(num);
            do {
                std::cout << "Do you want another num (y or n): ";
                std::getline(std::cin, another_num);
            } while(another_num != "y" && another_num != "n");
        }
        std::string sort_mode = "";
        while(sort_mode != "a" && sort_mode != "d") {
                std::cout << "Sort ascending or descending (a or d)? ";
                std::getline(std::cin, sort_mode);
            }
        if(sort_mode == "a")
            linked_list.sort_ascending();
        else
            linked_list.sort_descending();
        linked_list.print();
        std::cout << "You have " << linked_list.prime_nums(linked_list) << " prime number(s) in your list." << std::endl;
        again = "";
        while(again != "y" && again != "n") {
            std::cout << "Do you want to do this again (y or n)? ";
            std::getline(std::cin, again);
        }
    }
    return 0;
}

