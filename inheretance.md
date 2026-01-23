✅ What is Inheritance in C++03?

Inheritance allows one class (called the derived class) to inherit the properties and behaviors (data members and member functions) of another class (called the base class).

It promotes code reuse and enables polymorphism.

🔑 Types of Inheritance in C++03

There are 5 types of inheritance supported in C++ (C++03 and onwards):

--> Single Inheritance

--> Multiple Inheritance

--> Multilevel Inheritance

--> Hierarchical Inheritance

--> `Hybrid Inheritance

Each of these can use different access specifiers: public, protected, or private.

⚙️ Basic Syntax Example – Single Inheritance

```c
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal eats food" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog d;
    d.eat();   // Inherited from Animal
    d.bark();  // Dog's own function
    return 0;
}
```

✔️ Access Specifiers:

public inheritance: public & protected members of base stay the same in derived class

protected inheritance: public & protected become protected in derived

private inheritance: everything becomes private in derived

💥 C++03 Specific Considerations

No override or final keywords (introduced in C++11)

No explicitly =delete or =default constructors

No nullptr (use NULL)

Virtual inheritance and virtual functions are supported (enables polymorphism)

You must manually manage resources — no std::unique_ptr or shared_ptr (C++11+)

👀 Example – Virtual Function for Polymorphism

```c
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

void render(Shape* s) {
    s->draw();  // Dynamic dispatch
}

int main() {
    Shape shape;
    Circle circle;

    render(&shape);   // Drawing Shape
    render(&circle);  // Drawing Circle (polymorphism)
    return 0;
}
```

✔️ With virtual, the call is resolved at runtime, not compile time.

Would you like me to cover:

Multiple inheritance?

Virtual inheritance (diamond problem)?

Abstract classes and pure virtual functions?
