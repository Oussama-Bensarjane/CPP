#include "FragTrap.hpp"

int main() {
    FragTrap frag("Yuji");
    frag.highFivesGuys();
    frag.attack("target1");
    frag.takeDamage(50);
    frag.beRepaired(20);

    std::cout << "------------------------\n";

    FragTrap copy = frag;
    FragTrap assign("Another");
    assign = frag;

    std::cout << "------------------------\n";

    return 0;
}
