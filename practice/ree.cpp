
#include <iostream>
#include <unistd.h>
#include <cctype>

class Adder{
public:
	int add(int a, int b){ return a + b;}
	int add(float a, float b){ return a + b;}
	std::string add(const std::string& a,const std::string& b){ return a + b;}
};

int main(int argc, char **argv)
{

	std::cout << "int: " << Adder::add(

	)
	return (0);
}








/**
 * #include <iostream>
#include <string>

class Adder {
public:
    static int add(int a, int b) {
        return a + b;
    }

    static float add(float a, float b) {
        return a + b;
    }

    static std::string add(const std::string& a, const std::string& b) {
        return a + b;
    }
};

int main() {
    std::cout << "Int:   " << Adder::add(2, 3) << std::endl;             // 5
    std::cout << "Float: " << Adder::add(2.5f, 3.5f) << std::endl;       // 6.0
    std::cout << "Str:   " << Adder::add("Hi, ", "there!") << std::endl; // "Hi, there!"

    return 0;
}

 */