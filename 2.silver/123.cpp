#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "abc";
	
	str[4] = 'z';
	cout << "str = ["<< str << "]\n";
	cout << "str[0] = [" << str[0] << "]\n";
}