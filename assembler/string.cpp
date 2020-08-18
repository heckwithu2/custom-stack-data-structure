//Jeremiah Heck
//project 2 milestone 1
//2/17/2020

#include "string.hpp"
#include <iostream>
#include <vector>


String::String() {
	str[0] = '\0';
}

String::String(char x) {
	str[0] = x;
	str[1] = '\0';
}

String::String(const char x[]) {
	for (int i = 0; i < STRING_SIZE; ++i) {
		if (x[i] != '\0') {
			str[i] = x[i];
			str[i + 1] = '\0';
		}
		else {
			i = STRING_SIZE;
		}
	}
}

char& String::operator[](int x) {

	return str[x];

}

char String::operator[](int x)const {

	return str[x];

}

int String::capacity() const {
	int storage = 0;
	for (int i = 0; i < STRING_SIZE; ++i) {
		if (str[i] == '\0') {
			storage++;
		}
	}
	return storage;
}

int String::length() const {
	int length = 0;
	for (int i = 0; i < STRING_SIZE; ++i) {
		if (str[i] != '\0') {
			length++;
		}
		else {
			return length;
		}
	}
	return length;
}

String String::operator+(const String& right) const {
	//make a copy of the left
	String Concatenation;
	int g = length();
	for (int i = 0; i < g; ++i) {
		Concatenation.str[i] = str[i];
		Concatenation.str[i + 1] = '\0';
	}
	//find the end of the left string
	int end = 0;
	bool done = false;
	for (int i = 0; i < STRING_SIZE; ++i) {
		if (str[i] == '\0' && done == false) {
			end = i;
			done = true;
		}
	}
	//add the second string to the end of it.
	g = right.length();
	for (int i = 0; i < g; ++i) {
		Concatenation.str[end + i] = right[i];
		Concatenation.str[end + i + 1] = '\0';
	}
	/*for (int i = 0; i < Concatenation.length(); ++i) {
	std::cout << Concatenation.str[i] << std::endl;
	}*/
	return Concatenation;
}

bool String::operator==(const String& right)const {
	for (int i = 0; i < STRING_SIZE; ++i) {
		if (str[i] != right.str[i]) {
			return false;
		}
	} return true;
}

bool String::operator<(const String& rightS)const {
	int left = 0;
	int right = 0;
	left = length();
	right = rightS.length();

	if (left < right) {
		return true;
	}
	else {
		return false;
	}
}

std::istream& operator>>(std::istream& is, String& x) {
	//this needs work
	char array[STRING_SIZE] = { '\0' };
	for (int i = 0; i > STRING_SIZE; ++i) {
		is >> array[i];
	}
	String newString(array);
	return is;
}

std::ostream& operator<<(std::ostream& os, const String& x) {
	if (x == ' ' || x == " ") {
		os << " ";
		return os;
	}
	else {
		for (int i = 0; i < x.length(); ++i) {
			os << x.str[i];
		}
		return os;
	}
}

String operator+ (const char x[], const String& right) {
	String left(x), concatenation;
	concatenation = left + right;
	return concatenation;
}

String operator+ (char x, const String& right) {
	String left(x), concatenation;
	concatenation = left + right;
	return concatenation;
}

bool operator== (const char x[], const String& right) {
	String left(x);
	for (int i = 0; i < STRING_SIZE; ++i) {
		if (left[i] != right[i]) {
			return false;
		}
	} return true;

}

bool operator== (char x, const String& right) {
	String left(x);
	for (int i = 0; i < STRING_SIZE; ++i) {
		if (left[i] != right[i]) {
			return false;
		}
	} return true;

}

bool operator< (const char x[], const String& rightS) {
	String leftS(x);
	int left = 0;
	int right = 0;
	left = leftS.length();
	right = rightS.length();

	if (left < right) {
		return true;
	}
	else {
		return false;
	}

}

bool operator< (char x, const String& rightS) {
	String leftS(x);
	int left = 0;
	int right = 0;
	left = leftS.length();
	right = rightS.length();

	if (left < right) {
		return true;
	}
	else {
		return false;
	}

}

bool operator> (const String& leftS, const String& rightS) {
	int left = 0;
	int right = 0;
	left = leftS.length();
	right = rightS.length();

	if (left > right) {
		return true;
	}
	else {
		return false;
	}

}

bool operator< (const String& leftS, const String& rightS) {
	int left = 0;
	int right = 0;
	left = leftS.length();
	right = rightS.length();

	if (left < right) {
		return true;
	}
	else {
		return false;
	}

}

bool operator!= (const String& left, const String& right) {

	for (int i = 0; i < STRING_SIZE; ++i) {
		if (left[i] == right[i]) {
			return false;
		}
	} return true;


}
bool operator<=(const String& left, const String& right) {

	for (int i = 0; i < STRING_SIZE; ++i) {
		if (left[i] != right[i] || left[i] < right[i]) {
			return false;
		}
	} return true;

}

bool operator>=(const String& left, const String& right) {

	for (int i = 0; i < STRING_SIZE; ++i) {
		if (left[i] != right[i] || left[i] > right[i]) {
			return false;
		}
	} return true;

}

String String::substr(int start, int end) {
	String sub;
	for (int i = start; i <= end; ++i) {

		sub.str[i] = str[i];

	}
	return sub;
}

int String::findch(int pos, char ch) {

	for (int i = pos; i <= STRING_SIZE; ++i) {
		if (str[i] == ch) {
			return i;
		}
	}
	return -1;
}

int String::findstr(int pos, const String& stringWithin) {
	int lengthright = stringWithin.length();
	int right = 0;
	bool check = true;
	for (int i = pos; i <= STRING_SIZE; ++i) {
		if (str[i] == stringWithin.str[right]) {
			for (int x = i; x < lengthright + i; ++x) {
				if (str[x] != stringWithin.str[right]) {
					check = false;
				}
				else {
					right++;
					check = true;
				}
			}
			if (check == true) {
				return i;
			}
			right = 0;
		}
	}

	return -1;
}

void String::reset() {
	str[0] = '\0';
}

std::vector<String>  split(const String& bigString) {
	int count = 0;
	for (int i = 0; i < bigString.length(); ++i) {
		//ignore spaces
		if (bigString[i] != '\0' || ' ') {
			count++;
		}
	}
	std::vector<String> clean(count);

	for (int i = 0; i < bigString.length(); ++i) {
		//ignore spaces
		if (bigString[i] != '\0' || ' ') {
			clean[i] = bigString[i];
		}
	}
	return clean;
}