#include "Cat.hpp"

Cat::Cat() : AAnimal(), brain(new Brain()) {
	type = "Cat";
	std::cout << "Cat constructed!" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructed!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assigned!" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		if (brain) delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructed!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int idx, const std::string& idea) {
	if (brain) brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const {
    if (brain)
        return brain->getIdea(idx);
    return "";
}
