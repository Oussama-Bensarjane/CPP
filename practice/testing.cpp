#include <iostream>

using namespace std;


int add(int a, int b){return (a + b);}
int sub(int a, int b){return (a - b);}
int mult(int a, int b){return (a * b);}


int main()
{
    int (*ops[3])(int, int) = {add, sub, mult};

    cout << (*ops[0])(1, 1) << endl;//add
    cout << ops[1](1, 1) << endl;//sub
    cout << ops[2](1, 1) << endl;//multi


}
