#include "BigInt.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	
	string num1;
	int num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;

	BigInt bignum1(num1);
	
	BigInt bignum3 = bignum1 + num2;
	cout << "Sum: " << bignum3 << endl;

	return 0;
}