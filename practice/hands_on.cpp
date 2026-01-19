#include <iostream>

class MyClass{
private:
	int* _value;

public:


	MyClass();									// Default Constactor
	MyClass(const MyClass& other);				// Copy constractor
	MyClass& operator=(const MyClass& other);	// Copy Assignement operator // accept const refrence to the object to copied 
	~MyClass();									// Default Destactor

	void	setValue(int Val);
	int	getValue() const;

};
//////////////////////////////

MyClass::MyClass(): _value(new int(0)){
	std::cout << "Default Constactor CALLED\n";
}

MyClass::MyClass(const MyClass& other) : _value(new int(*other._value)){
	std::cout << "Copy Constractor CALLED\n";
}

MyClass::~MyClass(){
	std::cout << "Default Destactor CALLED\n";
	delete _value;
}


MyClass& MyClass::operator=(const MyClass& other){
	std::cout << "Copy assinment operator CALLED\n";
	if (this != &other){
		delete _value;
		_value = new int(*other._value);
	}
	return *this; // Return refrence to the current object TO ALLOW CHAINED ASSIGNMENT !!! a=b=c;
}

void MyClass::setValue(int val){

	*_value = val;
}
int MyClass::getValue() const{

	return *_value;
}

//////////////////////////////


int main()
{
	MyClass a;
	a.setValue(42);

	MyClass b = a; // copy constractor : copy initialisation
	MyClass c;

	c = a; // copy assignment

	std::cout << "a: " << a.getValue() << std::endl;
	std::cout << "b: " << b.getValue() << std::endl;
	std::cout << "c: " << c.getValue() << std::endl;

}

/**
 * Orthodox canonical form AKA Rule of 4. (4 essential member function);
 * Default constactor 		--> MyClass()
 * Copy constactor			--> Myclass(const Myclass& other)
 * Copy assignment operator	--> MyClass& operaator=(const MyClass& other)
 * Destructor				--> ~MyClass()
 * 
 * -----> this to avoid: 1- Double free ;2- Memory leak ;3- Shallow copies .
 * --> SHALLOW COPIES : a shallow copy; copies pointer value and not the data it points to; 
 * 						leading to: both object points to the same memory.
 * 						Causing : double free, memory leaks.
 * 
 */

