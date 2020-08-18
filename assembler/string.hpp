#pragma once
//Jeremiah Heck
//project 2 milestone 1
//2/17/2020

#ifndef STRING_HPP_
#define STRING_HPP_

#include <iostream>
#include <vector>
const int STRING_SIZE = 256;

//The size of the String.
////////////////////////////////////////////////////
// CLASS INV:   str[length()] == 0 &&
//              0 <= length() <= capacity() &&
//              capacity() == STRING_SIZE - 
//

class String {
public:
	String();                     //Empty string
	String(char);                 //Stirng('x')
	String(const char[]);         //String("abcd")
	char&   operator[]    (int);                  //Accessor/Modifier
	char    operator[]    (int)            const; //Accessor
	int     capacity()               const; //Max chars that can be stored (not including null terminator)
	int     length()               const; //Number of char in string
	String  operator+     (const String&)  const; //Concatenation
	bool    operator==    (const String&)  const;
	bool    operator<     (const String&)  const;
	String substr(int, int);
	int findch(int, char);
	int findstr(int, const String&);
	void reset();
	//friend  std::istream& operator>>(std::istream&, String&);
	friend  std::ostream& operator<<(std::ostream&, const String&);
	friend  std::vector<String>  split(const String&);
private:
	char str[STRING_SIZE];
};

String  operator+       (const char[], const String&);
String  operator+       (char, const String&);
bool    operator==      (const char[], const String&);
bool    operator==      (char, const String&);
bool    operator<       (const char[], const String&);
bool    operator<       (char, const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);




#endif STRING_HPP_
