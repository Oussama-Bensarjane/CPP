#include "PhoneBook.hpp"
#include <limits>
#include <sstream>

PhoneBook::PhoneBook() : _nextIndex(0), _size(0) {}

PhoneBook::~PhoneBook() {}

void    PhoneBook::welcome(void) const {
    std::cout << std::endl;
    std::cout << "Welcome to Your Awesome PhoneBook" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: To quit the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::addContact(void) {
    this->_contacts[this->_nextIndex].init();
    this->_contacts[this->_nextIndex].setIndex(this->_nextIndex);
    this->_nextIndex = (this->_nextIndex + 1) % 8;
    if (this->_size < 8)
        this->_size++;
}

void    PhoneBook::printContacts(void) const {
    std::cout << "------------- PHONEBOOK CONTACTS -------------" << std::endl;
    for (int i = 0; i < this->_size; i++) {
        this->_contacts[i].view(i);
    }
    if (this->_size == 0)
        std::cout << "(no contacts yet)" << std::endl;
    std::cout << std::endl;
}

int     PhoneBook::_readInput() const {
    if (this->_size == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return -1;
    }

    int     input = -1;
    bool    valid = false;
    std::string line;
    do
    {
        std::cout << "Please enter the contact index: " << std::flush;
        if (!std::getline(std::cin, line))
        {
            std::cin.clear();
            std::cout << "Input stream error; please try again." << std::endl;
            continue;
        }
        std::istringstream iss(line);
        if (iss >> input && input >= 0 && input < this->_size)
            valid = true;
        else
            std::cout << "Invalid index; please Enter it again." << std::endl;
    } while (!valid);
    return input;
}

void    PhoneBook::search(void) const {
    int i = this->_readInput();
    if (i >= 0)
        this->_contacts[i].display(i);
}