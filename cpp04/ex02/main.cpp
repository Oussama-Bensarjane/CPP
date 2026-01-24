#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const int SIZE = 4;
    std::cout << "********POLYMORPHISM********" << std::endl;

    AAnimal* animals[SIZE];
    int i;
    std::cout << "[1] creating Cat classes..." << std::endl;
    for(i = 0; i < SIZE/2; i++)
    {
        animals[i] = new Cat();
    }
    std::cout << "[2] creating Dog classes..." << std::endl;
    for(i = SIZE/2; i < SIZE; i++)
    {
        animals[i] = new Dog();
    }
    std::cout << "[3] calling sound funcs..." << std::endl;
    for (i = 0; i < SIZE; i++)
        animals[i]->makeSound();
    std::cout << "[4] destroying classes..." << std::endl;
    for(i = 0; i < SIZE; i++)
    {
        delete animals[i];
    }

    std::cout << "----------------\n";

    WrongAnimal* wrong = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();
    wrong->makeSound();
    wrongCat->makeSound();
    delete wrong;
    delete wrongCat;

    
    return 0;
}