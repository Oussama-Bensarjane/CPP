
#include <iostream>
#include <unistd.h>
#include <cctype>

class C {
	public:
	int i;
	std::string name;

	C() : name("med"), i(4) {};
	int operator+(C &c) {
		int res = this->i + c.i;
		return res;
	}
	int operator*(C &c) {
		int res = this->i * c.i;
		return res;
	}
	int operator*(int k) {
		int res = this->i * k;
		return res;
	}

	void operator<<(std::ostream &cout) {
	cout << "heyyyyy "<< this->name;
}
};

	int operator*(int k, C &c) {
		int res = k * c.i;
		return res;
	}

std::ostream &operator<<(std::ostream &cout, C &c) {
	cout << "welcome "<< c.name;
	return cout;
}

void ft_modify(int &k)
{
	k = 100;
}

std::ostream &operator<<(std::ostream &cout, char* ss) {
	if (ss == NULL)
		cout << "NULL";
	else
	{
		cout << " varr: " << (const char *)ss;
	}
	return cout;
}



std::ostream &operator<<(std::ostream &cout, std::string* ss) {
	if (ss == nullptr)
		cout << "NULL";
	else
		cout << "here: " << ss->data();
	return cout;
}

int main(int argc, char **argv)
{
	void *a = nullptr;
	void*  &s = a;
	int x = 5;
	int l = 0;
	char *cc = "cool";
	std::string dd = "dada";
	std::string *ss = &dd;
	std::cout << "s: " << ss << cc << " a:" << &a << '\n';
	int &y = l;
	std::cout << "y: " << y << '\n';
	y = 200;
	std::cout << "y: " << y << '\n';

	ft_modify(x);


	C ccc;

	std::cout << ccc << " " << (2 * ccc);

	ccc << std::cout;
	
	return (0);
}