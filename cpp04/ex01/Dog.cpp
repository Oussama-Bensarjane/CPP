#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructed!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructed!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assigned!" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        if (brain) delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructed!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int idx, const std::string& idea) {
    if (brain) brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const {
    return brain ? brain->getIdea(idx) : "";
}
