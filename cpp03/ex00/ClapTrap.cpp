#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructed (default)." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	: name(other.name), hitPoints(other.hitPoints),
	energyPoints(other.energyPoints), attackDamage(other.attackDamage){
	std::cout << "ClapTrap " << other.name << " copy constructed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	std::cout << "ClapTrap copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " can't attack (no energy or hit points)!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
		return ;
	}
	if (amount > static_cast<unsigned int>(hitPoints))
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! (HP: " << hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		if (amount > static_cast<unsigned int>(INT32_MAX - hitPoints)) {
			hitPoints = INT32_MAX;
		}
		else
			hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points! (HP: " << hitPoints << ")" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " can't be repaired (no energy or hit points)!" << std::endl;
	}
}