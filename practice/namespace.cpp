#include <iostream>

namespace Tiznit
{
    int var = 20;
    void Display ()
    {
        std::cout << "Hello from Tiznit, The nmr of houses are : " << Tiznit::var << std::endl;
    }
}


int main()
{
    Tiznit::Display();
}