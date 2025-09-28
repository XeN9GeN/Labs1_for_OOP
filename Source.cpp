#include "BigInt.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	
	string num1;
	string num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;

	BigInt bignum1(num1);
	BigInt bignum_sum = bignum1 + num2;
	BigInt bignum_dif = bignum1 - num2;
	BigInt bignum_prod = bignum1 * num2;
	BigInt bignum_quot = bignum1 / num2;
	
	cout << "Sum: " << bignum_sum << endl;
	cout << "Difference: " << bignum_dif << endl;
	cout << "Product: " << bignum_prod << endl;
	cout << "Quotient: " << bignum_quot << endl;
	return 0;
}