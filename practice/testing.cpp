#include <iostream>

// Defining a namespace called 'example'
namespace example {
    int variable = 42;

    void display() {
        std::cout << "This is the example namespace. " << std::endl;
    }
}

// Another namespace with the same name as 'example', but in a different scope
namespace another {
    int variable = 99;

	void display() {
        std::cout << "This is the another namespace. " << std::endl;
	}
}

int main() {
    // Accessing elements from the 'example' namespace
    std::cout << "Value from 'example' namespace: " << example::variable << std::endl;
    example::display();
    // Accessing elements from the 'another' namespace
    std::cout << "Value from 'another' namespace: " << another::variable << std::endl;
		
    return 0;
}
/*
g++ -std=c++98
*/