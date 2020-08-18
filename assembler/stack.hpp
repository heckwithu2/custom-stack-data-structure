#ifndef STACK_HPP_
#define STACK_HPP_
////////////////////////////////////////////////////////////////////////////
// File: stack.hpp
// Programmer: Jeremiah
// Updated:    10/2019
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
#include <new>
#include <iostream>
#include <vector>
#include <fstream>
////////////////////////////////////////////////////////////////////////////        
template<typename T>
class Node {
public:
	T data;
	class Node<T> *next;
};
////////////////////////////////////////////////////////////////////////////
// CLASS INV:
template <typename T>
class stack {
public:
	stack();
	stack(const stack<T>&);
	~stack();
	void      swap(stack<T>&);
	stack<T>& operator= (stack<T>);
	bool      empty() const;
	T         getTos() const;
	T         pop();
	void      push(const T&);
	void	  output();
	int		  count();
private:
	Node<T>   *tos;
};

//definitions

template <typename T>
stack<T>::stack() {
	
}

template <typename T>
stack<T>::stack(const stack<T>& copy) {
	tos = copy.tos;
}

template <typename T>
stack<T>::~stack() {

}

template <typename T>
void stack<T>::swap(stack<T>&) {

}

template <typename T>
stack<T>& stack<T>::operator=(stack<T> right) {
	while (tos != NULL) {
		right.tos = tos;
		right.tos->data = tos->data;
		tos = tos->next;
	}
}


template <typename T>
bool stack<T>::empty() const {
	if (tos != NULL) {
		return false;
	}
	return true;
}

template <typename T>
T stack<T>::getTos() const {
	if (tos != nullptr) {
		return tos->data;
	}
}

template <typename T>
T stack<T>::pop() {
	Node<T>* temp = (class Node<T>*) malloc(sizeof(class Node<T>));
	temp = tos;
	T x = tos->data;
	//locate node
	if (temp->data == x && temp != NULL) {
		temp = tos->next;
		tos = temp;
		return x;
	}

	if (temp == NULL)
		return x;

	return x;
}

template <typename T>
void stack<T>::push(const T& x) {
	Node<T>* newNode = (class Node<T>*) malloc(sizeof(class Node<T>));
	newNode->next = NULL;
	newNode->data = x;

	if (tos == NULL) {
		tos = newNode;
		return;
	}
	else {
		newNode->next = tos;		
		tos = newNode;
		return;
	}
}

template <typename T>
void stack<T>::output() {
	Node<T>* temp = (class Node<T>*) malloc(sizeof(class Node<T>));
	temp = tos;
	int count = 0;
	while (temp != NULL) {
		std::cout << temp->data;
		temp = temp->next;
	}
}

template <typename T>
int stack<T>::count() {
	Node<T>* temp = (class Node<T>*) malloc(sizeof(class Node<T>));
	temp = tos;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

#endif
