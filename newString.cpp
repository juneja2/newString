#include "newString.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
using namespace std;

newString::newString() {
	cout << "Constructor with no parameter running\n";
	ptrLength = 0;
	ptr = new(nothrow) char[1];
	if (ptr == nullptr) {
		cout << "Wasn't able to allocate memory in one argument constructor\n";
		exit(EXIT_FAILURE);
	}
	ptr[0] = '\0';
}//Correct
newString::newString(const char* str) {
	cout << "Constructor with one parameter running\n";
	int j = 0;
	while (str[j] != '\0')
		j++;
	ptrLength = j;
	ptr = new(nothrow) char[ptrLength + 1];
	if (ptr == nullptr) {
		cout << "Wasn't able to allocate memory in one argument constructor\n";
		exit(EXIT_FAILURE);
	}			
	int i = 0;
	for(; i < ptrLength; i++)
		ptr[i] = str[i];
	ptr[i] = '\0';
}// Correct

newString::newString(const newString& obj) {
	cout << "Copy constructor running\n";
	ptrLength = obj.ptrLength;
	ptr = new(nothrow) char[ptrLength + 1];
	if (ptr == nullptr) {
		cout << "Wasn't able to allocate memory in one argument constructor\n";
		exit(EXIT_FAILURE);
	}
	int i = 0;
	for (; i < ptrLength; i++)
		ptr[i] = obj.ptr[i];
	ptr[i] = '\0';
}
newString::~newString() {
	cout << "Destructor running\n";
	delete[] ptr;
}// correct
const newString& newString::operator=(const newString& s) {
	if (this != &s){
		delete [] ptr;
		ptrLength = s.ptrLength;
		ptr = new(nothrow) char[ptrLength + 1];
		if (ptr == nullptr) {
			cout << "Wasn't able to allocate memory in one argument constructor\n";
			exit(EXIT_FAILURE);
		}
		int i = 0;
		for (; i < ptrLength; i++)
			ptr[i] = s.ptr[i];
		ptr[i] = '\0';
	} 
	return *this;
}
newString newString::operator+(const newString & str) {
	newString s;
	delete[] s.ptr;

	s.ptrLength = ptrLength + str.ptrLength;
	s.ptr = new(nothrow) char[s.ptrLength + 1];
	if (s.ptr == nullptr) {
		cout << "Wasn't able to allocate memory in operator + function\n";
		exit(EXIT_FAILURE);
	}

	int i = 0;
	for (; i < ptrLength; i++)
		s.ptr[i] = ptr[i];
	// i = ptrLength so we need to make the index for str.ptr = 0 
	for (; i < s.ptrLength; i++)
		s.ptr[i] = str.ptr[i - ptrLength];
	s.ptr[i] = '\0';
	return s;
}
char& newString::operator[](int index)const {
	try {
		cout << "char & [] running\n";
		if (index >= 0 && index < ptrLength) return ptr[index];
		else throw out_of_range("Index out of bounds\n");
	}
	catch (out_of_range obj) {
		cout << obj.what();
		exit(EXIT_FAILURE);
	}
}
bool newString::operator==(const newString& s)const {
	return(strcmp(ptr, s.ptr) == 0);
}
bool newString::operator!=(const newString& s)const {
	return(strcmp(ptr, s.ptr) != 0);
}
bool newString::operator>(const newString& s)const {
	return(strcmp(ptr, s.ptr) > 0);
}
bool newString::operator<(const newString& s)const {
	return(strcmp(ptr, s.ptr) < 0);
}
bool newString::operator>=(const newString& s)const {
	return(*this > s || *this == s);
}
bool newString::operator<=(const newString& s)const {
	return(*this < s || *this == s);
}
ostream& operator<<(ostream& out, const newString& s) {
	out << s.ptr << endl;
	return out;
}
istream& operator>>(istream& in, newString& s) {
	char temp[100];
	cout << "Please enter a string ";
	cin >> setw(sizeof(temp)-1) >>  temp;

	delete[] s.ptr;
	s.ptrLength = strlen(temp);
	s.ptr = new(nothrow) char[s.ptrLength + 1];
	if (s.ptr == nullptr) {
		cout << "Wasn't able to allocate memory in one argument constructor\n";
		exit(EXIT_FAILURE);
	}

	int i = 0;
	for (; temp[i] != '\0'; i++)
		s.ptr[i] = temp[i];
	s.ptr[i] = '\0';
	return in;
}