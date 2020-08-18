#pragma once
//Jeremiah Heck
//7/27/2020

#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <iostream>
#include <vector>
#include "string.hpp"
#include "stack.hpp"

//String readExpression(String);
void infixToPostfix(const char x[]);//converts infix to postfix
bool operCheck(int, std::vector<String> &);
template <typename T>
void postfixToAssembly(stack<T>);//converts postfix to assembly
String operAssembly(String &, stack<String> &);
char charBack(int);
#endif