#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie* heapZombie = newZombie("HeapFoo");
	heapZombie->announce();

	randomChump("StackBoo");

	delete heapZombie;

	return 0;
}