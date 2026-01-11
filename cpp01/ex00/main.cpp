#include "Zombie.hpp"

int main()
{
	Zombie* heapZombie = newZombie("HeapFoo");
	heapZombie->announce();

	randomChump("StackBoo");

	delete heapZombie;

	return 0;
}