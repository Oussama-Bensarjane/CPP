#include "PhoneBook.hpp"
#include <iostream>

int main(void) {
    PhoneBook book;
    std::string input;

    book.welcome();
    while (true) {
        std::cout << "> " << std::flush;
        if (!std::getline(std::cin, input))
            break;
        if (input == "EXIT") 
            break;
        if (input == "ADD")
            book.addContact();
        else if (input == "SEARCH") {
            book.printContacts();
            book.search();
        } else if (!input.empty()) {
            std::cout << "Unknown command. Use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}