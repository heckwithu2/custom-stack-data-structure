
//Jeremiah Heck
//7/27/2020

#include "string.hpp"
#include "stack.hpp"
#include <iostream>
#include "utilities.hpp"
#include <fstream>


void infixToPostfix(const char x[]) {

	std::fstream file(x);

	if (!file.is_open()) {
		std::cout << "Unable to open file\n";
	}

	char token;
	String entity;
	int begining = 0;
	do {
		stack<String> postfix;
		do {
			file.get(token); //read token
			if (token != ';') {
				std::cout << token;
			}
			else {
				std::cout << token << std::endl;
			}
			if (token != ' ' && token != '(') {
				if (token == ')') {
					if (postfix.getTos() == " ") {
						postfix.pop();
					}
					String right(postfix.pop());
					String oper(postfix.pop());
					String left(postfix.pop());
					String expression = left + right + oper;
					postfix.push(expression);	
				}
				else {
					String push(token);
					entity = entity + push;
					begining = 1;
				}
			}
			if (token == ' ') {
				if (begining == 1) {	
					if (postfix.getTos() == " ") {
						postfix.pop();
					}
					postfix.push(entity);
					entity.reset();
					begining = 0;
				}
			}
			if (postfix.getTos() == " ") {
				postfix.pop();
			}
		} while (token != ';');	
		postfix.output();
		postfixToAssembly(postfix);
	} while (file.eof() == false);

	file.close();
	//outputFile.close();
}

template <typename T>
void postfixToAssembly(stack<T> postfix) {
	int size = postfix.count();
	String bigString;
	//make on big string out of stack
	for (int i = 0; i < size; ++i) {
		String temp;
		temp = postfix.pop();
		bigString = bigString + temp;
	}

	//convert string to vector
	std::vector<String> cleanString;
	cleanString = split(bigString);
		
	//sift through vector to make new stack
	stack<String> assemblerStack;
	
	int tmpCount = 1;
	for (int i = 0; i < cleanString.size(); ++i) {
		if (operCheck(i, cleanString) == false) {
			//if no operator
			//store in new stack
			assemblerStack.push(cleanString[i]);
		}
		else if (operCheck(i, cleanString) == true) {
			String operat = operAssembly(cleanString[i], assemblerStack);
			String right = assemblerStack.pop();
			String left = assemblerStack.pop();

			//output
			std::cout << std::endl;
			std::cout << "   LD    ";
			std::cout << right << std::endl;
			std::cout << "   " + operat + "    ";
			std::cout << left << std::endl;
			std::cout << "   ST    TMP";
			std::cout << tmpCount;
			char num = charBack(tmpCount);
			String TMP("TMP");
			String tmp(num);
			TMP = TMP + tmp;
			assemblerStack.push(TMP);
			tmpCount++;
		}
	}
	
}

bool operCheck(int x, std::vector<String> &vecString) {
	if (vecString[x] == "+" || vecString[x] == "-" || vecString[x] == "/" || vecString[x] == "*") {
		return true;
	}
	else {
		return false;
	}
}

String operAssembly(String &elem, stack<String> &assemStack) {
	if (elem == '+') {
		String message("AD");
		return message;
	}
	else if (elem == '*') {
		String message("MU");
		return message;
	}
	else if (elem == '/') {
		String message("DV");
		return message;
	}
	else if (elem == '-') {
		String message("SB");
		return message;
	}
	
}

char charBack(int x) {
	if (x == 1) {
		return '1';
	}
	else if (x == 2) {
		return '2';
	}
	else if (x == 3) {
		return '3';
	}
	else if (x == 4) {
		return '4';
	}
	else if (x == 5) {
		return '5';
	}
	else if (x == 6) {
		return '6';
	}
	else if (x == 7) {
		return '7';
	}
	else if (x == 8) {
		return '8';
	}
	else if (x == 9) {
		return '9';
	}
	else if (x == 10) {
		return '10';
	}
}