#include "PhoneBook.hpp"

static bool isValidInput(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isprint((unsigned char)str[i]))
            return false;
    }
    return true;
}

int main(void) {
    PhoneBook book;
    std::string input;

    book.welcome();
    while (true) {
        std::cout << "> " << std::flush;
        if (!std::getline(std::cin, input))
            break;
        if (!isValidInput(input)) {
            std::cout << "Invalid input." << std::endl;
            continue;
        }
        if (input == "EXIT") 
            break;
        if (input == "ADD")
            book.addContact();
        else if (input == "SEARCH") {
            book.printContacts();
            book.search();
        }
        else if (!input.empty())
            std::cout << "Unknown command. Use ADD, SEARCH, or EXIT." << std::endl;
    }
    return 0;
}