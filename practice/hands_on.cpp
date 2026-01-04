#include <iostream>

namespace mathx {int add(int a, int b) {return a + b;} int sub(int a, int b) {return (a - b);}}

int main()
{
	using mathx::add;

	int s = add(10, 11);
}