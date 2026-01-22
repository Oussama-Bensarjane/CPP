#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("Toji");
    scav.attack("target1");
    scav.takeDamage(30);
    scav.beRepaired(100);
    scav.guardGate();

    std::cout << "------------------------\n";

    ScavTrap copy = scav;
    ScavTrap assign("Another");
    assign = scav;

	std::cout << "------------------------\n"; 

    return 0;
}
