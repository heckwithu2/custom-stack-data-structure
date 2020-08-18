#include "string.hpp"
#include "stack.hpp"
#include <iostream>
#include "utilities.hpp"
#include <vector>
#include <string>

int main() {
	char x[] = { "data3-2-1.txt" };
	std::cout << "Please enter the name of your txt file containing your infix expression. (Make sure its in the project, and type in the .txt extension)" << std::endl;
	std::cin >> x;

	infixToPostfix(x);
	system("pause");
}


