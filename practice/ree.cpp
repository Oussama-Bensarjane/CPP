#include <iostream>
#include <string>

namespace Dchira 
{
	int var = 12;
	void Display ()
	{
		std::cout << "My lovely Toown called "; 
	}
}

int main()
{
	std::cout << Dchira::var << std::endl;
}