
#ifndef NEW_STRING_H
#define NEW_STRING_H
#include <iostream>
using namespace std;
class newString {
private:
	char * ptr;
	int ptrLength;
public:
	newString();
	newString(const char*);
	newString(const newString&);
	~newString();

	friend ostream& operator<<(ostream&, const newString&);
	friend istream& operator>>(istream&, newString&);

	const newString& operator=(const newString& s);
	char& operator[](int)const;
	newString operator+(const newString &);

	bool operator>(const newString& s)const;
	bool operator<(const newString& s)const;
	bool operator>=(const newString& s)const;
	bool operator<=(const newString& s)const;
	bool operator==(const newString& s)const;
	bool operator!=(const newString& s)const;
};
#endif