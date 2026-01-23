#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "----------------\n";
    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;
    std::cout << "Type of meta: " << meta->getType() << std::endl;

    std::cout << "----------------\n";

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "----------------\n";

    delete meta;
    delete j;
    delete i;

    return 0;
}