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

	if (bignum1 == bignum2)
		cout << "Numbers are equal\n";
	else if (bignum1 > bignum2)
		cout << "First number is greater than second\n";
	else if(bignum1 < bignum2)
		cout << "Second number is greater than second\n";
	else if(bignum1>=bignum2)
		cout << "First number is greater than or equal to second\n";
	else if (bignum1 <= bignum2)
		cout << "Second number is greater than or equal to first\n";

	//BigInt bignum3 = oper.op_mult(bignum1, bignum2);
	//BigInt bignum4 = oper.op_div(bignum1, bignum2);

	cout << "First number: " << bignum1 << endl;	
	cout << "Second number: " << bignum2 << endl;
	cout << "\n";
	//cout << "Sum: " << bignum3 << endl;
	//cout << "Diff: " << bignum4 << endl;
	return 0;
}