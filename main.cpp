#include "newString.h"
#include <iostream>
using namespace std;
void func(newString s);
int main(){
	newString s0("Parshant");
	func(s0);

	newString str("My name is ");
	cout << "str = " << str;

	str = str + s0;
	cout << "After str = str + s0, str = " << str;

	newString s1;
	cin >> s0 >> s1;
	cout << "s0 = " << s0;
	cout << "s1 = " << s1;
	
	
	cout << "s1[0] = " << s1[0] << endl;
	cout << "Before any operation on s1, s1 = " << s1;
	s1[3] = 'K';
	cout << "After s1[3] = 'K' s1 = " << s1;
	
	cout << "s1 > s0 = " <<  (s1 > s0) << "\n";
	cout << "s1 >= s0 = " << (s1 >= s0) << "\n";
	cout << "s1 == s0 = " << (s1 == s0) << "\n";
	cout << "s1 < s0 = " << (s1 < s0) << "\n";
	cout << "s1 <= s0 = " << (s1 <= s0) << "\n";
	cout << "s1 != s0 = " << (s1 != s0) << "\n";

	return 0;
}
void func(newString s) {
	cout << "newString passed to func = " << s;
}
/*
Constructor with one parameter running
Copy constructor running
newString passed to func = Parshant
Destructor running
Constructor with one parameter running
str = My name is
Constructor with no parameter running
Copy constructor running
Destructor running
Destructor running
After str = str + s0, str = My name is Parshant
Constructor with no parameter running
Please enter a string Hello
Please enter a string Howdy?
s0 = Hello
s1 = Howdy?
char & [] running
s1[0] = H
Before any operation on s1, s1 = Howdy?
char & [] running
After s1[3] = 'K' s1 = HowKy?
s1 > s0 = 1
s1 >= s0 = 1
s1 == s0 = 0
s1 < s0 = 0
s1 <= s0 = 0
s1 != s0 = 1
Destructor running
Destructor running
Destructor running
Press any key to continue . . .
*/