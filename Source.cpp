#include "BigInt.h"
#include "BigIntCompare.h"
#include "BigIntOperations.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string num1;
	int num2;
	cout << "Enter first number: " << endl;
	cin >> num1;
	cout << "Enter second number: " << endl;
	cin >> num2;

	BigInt bignum1(num1);
	BigInt bignum2(num2);
	
	cout << "First number: " << bignum1 << endl;
	cout << "Second number: " << bignum2 << endl;
	return 0;
}