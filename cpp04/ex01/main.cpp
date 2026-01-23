#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "--- Array of Animals Test ---" << std::endl;
    const int N = 6;
    Animal* animals[N];
    for (int i = 0; i < N / 2; ++i)
        animals[i] = new Dog();
    for (int i = N / 2; i < N; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < N; ++i) {
        std::cout << "Animal[" << i << "] type: " << animals[i]->getType() << ", sound: ";
        animals[i]->makeSound();
    }

    std::cout << "--- Deep Copy Test ---" << std::endl;
    Dog* dog1 = new Dog();
    dog1->setIdea(0, "Chase cats");
    dog1->setIdea(1, "Eat food");
    Dog* dog2 = new Dog(*dog1); // Copy constructor
    std::cout << "dog1 idea[0]: " << dog1->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2->getIdea(0) << std::endl;
    dog2->setIdea(0, "Sleep");
    std::cout << "After change, dog1 idea[0]: " << dog1->getIdea(0) << std::endl;
    std::cout << "After change, dog2 idea[0]: " << dog2->getIdea(0) << std::endl;

    Cat* cat1 = new Cat();
    cat1->setIdea(0, "Climb tree");
    Cat* cat2 = new Cat(*cat1); // Copy constructor
    std::cout << "cat1 idea[0]: " << cat1->getIdea(0) << std::endl;
    std::cout << "cat2 idea[0]: " << cat2->getIdea(0) << std::endl;
    cat2->setIdea(0, "Nap");
    std::cout << "After change, cat1 idea[0]: " << cat1->getIdea(0) << std::endl;
    std::cout << "After change, cat2 idea[0]: " << cat2->getIdea(0) << std::endl;

    delete dog1;
    delete dog2;
    delete cat1;
    delete cat2;

    std::cout << "--- Deleting Animals ---" << std::endl;
    for (int i = 0; i < N; ++i)
        delete animals[i];

    std::cout << "--- End of Tests ---" << std::endl;
    return 0;
}