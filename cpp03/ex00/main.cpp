#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Toji");

	a.attack("target1");
	a.takeDamage(5);
	a.beRepaired(3);

	std::cout << "------------------\n";

	a.attack("target2");
	a.takeDamage(20);
	a.beRepaired(4);
	a.takeDamage(1);

	std::cout << "------------------\n";

	ClapTrap b = a;
	b.attack("target3");
	a.takeDamage(1);

	std::cout << "------------------\n";
	
	ClapTrap c("Escanor");
	c = a;
	c.attack("target4");

	std::cout << "------------------\n";


    return 0;
}