# C++ Mini-Workshop – Module 1: Namespaces & `iostream`

## Goal
Understand how namespaces avoid name collisions and how to use standard input/output streams for console apps.

---

## Cheat Sheet

**Namespaces**
- Declare: `namespace mylib { /* names */ }`
- Use a qualified name: `mylib::foo()`
- Bring specific names into scope: `using mylib::foo;` (prefer local, not in headers)
- Alias: `namespace io = std; // or custom`
- Anonymous namespace (internal linkage in a translation unit): `namespace { /* ... */ }`

**Standard I/O Streams** (from `<iostream>`)
- Output: `std::cout << "text" << std::endl;` (note: `std::endl` flushes; `"\n"` usually faster)
- Input: `std::cin >> x;` (whitespace-delimited)
- Whole line: `std::getline(std::cin, line);`
- Error stream: `std::cerr << "error" << std::endl;`
- Formatting: `#include <iomanip>` e.g., `std::setw`, `std::setprecision`, `std::boolalpha`

**Common Best Practices**
- Avoid `using namespace std;` in headers or global scope—prefer qualified names or selective `using` inside functions.
- Keep `using` directives local to a `.cpp` when you control it.

---

## Micro‑Exercises (10–15 min)

### 1) Namespace Basics
Create two functions named `greet()` in different namespaces and call them explicitly.
```cpp
#include <iostream>

namespace english { void greet() { std::cout << "Hello" << '\n'; } }
namespace spanish { void greet() { std::cout << "Hola" << '\n'; } }

int main() {
    english::greet();
    spanish::greet();
}
```
**Task:** Add a third namespace `arabic` with `greet()` and call it.

---

### 2) Selective `using`
Define `add(int,int)` inside `mathx` and then locally bring **only** `add` into `main()`.
```cpp
namespace mathx { int add(int a, int b) { return a + b; } int sub(int a, int b) { return a - b; } }
int main() {
    using mathx::add;         // local using
    // using namespace mathx; // <- DON'T do this globally
    int s = add(3, 4);
    // int t = sub(5, 2);    // should NOT compile here unless qualified
    int t = mathx::sub(5, 2);
}
```
**Task:** Comment/uncomment lines to see the effect.

---

### 3) Namespace Aliases
Create an alias `mx` for `mathx` and use it with `mx::add`.
```cpp
namespace mathx { int mul(int a, int b) { return a * b; } }
namespace mx = mathx; // alias
int main() { std::cout << mx::mul(6, 7) << '\n'; }
```
**Task:** Add `pow2(int)` that returns `x*x` under `mathx` and call `mx::pow2`.

---

### 4) Basic `iostream` I/O
Read an `int` and a `std::string` (single word) and print them.
```cpp
#include <iostream>
#include <string>
int main() {
    int age; std::string name;
    std::cout << "Enter age and first name: ";
    std::cin >> age >> name;              // whitespace-delimited
    std::cout << "Hi " << name << ", age " << age << "\n";
}
```
**Task:** Replace the input to read a full line name using `std::getline`.
(Hint: after `>>`, consume leftover `\n` with `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');` then `getline`.)

---

### 5) Formatting Output
Print a floating-point number in fixed notation with 2 decimals, and booleans as `true/false`.
```cpp
#include <iostream>
#include <iomanip>
int main() {
    double pi = 3.14159265;
    bool flag = true;
    std::cout << std::fixed << std::setprecision(2) << pi << "\n";
    std::cout << std::boolalpha << flag << "\n";
}
```
**Task:** Also show `pi` with scientific notation (`std::scientific`) and width 12 (`std::setw(12)`).

---

## Stretch Task
Build a tiny program `calc.cpp` that:
1. Lives inside a namespace `calc`.
2. Exposes functions `add`, `sub`, `mul`, `div` (integer division with divide-by-zero check printing to `std::cerr`).
3. In `main()`, read an expression like `12 * 7` (number op number) from one line and print the result.
   - Use `std::getline` to read the line, parse with `std::istringstream`.
   - Support `+ - * /`.

**Expected run**
```
> 12 * 7
84
```
On divide-by-zero, print an error and exit non-zero.

---

## Review Checklist
- [ ] I can explain why `using namespace std;` is discouraged in headers.
- [ ] I know three ways to access names: qualified, selective `using`, alias.
- [ ] I can read/write with `std::cin`, `std::cout`, `std::cerr` and format output.

---

**When ready**: Reply “Module 1 done” and I’ll reveal reference solutions and move you to Module 2 (Classes, member functions, initialization lists).

