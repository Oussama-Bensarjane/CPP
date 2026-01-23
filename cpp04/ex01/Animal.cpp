#include "Animal.hpp"

Animal::Animal() : type("") {
    std::cout << "Animal constructed!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructed!" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assigned!" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructed!" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Some generic animal sound!" << std::endl;
}
