#include "BigInt.h"
#include "BigIntCompare.h"
#include "BigIntOperations.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	BigIntOperations oper;

	
	string num1;
	string num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;

	BigInt bignum1(num1);
	BigInt bignum2(num2);
	BigInt bignum3 = oper.op_plus(bignum1, bignum2);
	BigInt bignum4 = oper.op_minus(bignum1, bignum2);

	cout << "First number: " << bignum1 << endl;
	cout << "Second number: " << bignum2 << endl;
	cout << "Sum: " << bignum3 << endl;
	cout << "Difference: " << bignum4 << endl;
	return 0;
}