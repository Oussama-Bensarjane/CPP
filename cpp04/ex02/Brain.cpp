#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructed!" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructed!" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assigned!" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructed!" << std::endl;
}

void Brain::setIdea(int idx, const std::string& idea) {
    if (idx >= 0 && idx < 100) {
        ideas[idx] = idea;
    }
}

std::string Brain::getIdea(int idx) const {
    if (idx >= 0 && idx < 100) {
        return ideas[idx];
    }
    return "";
}
