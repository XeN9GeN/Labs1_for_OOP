#include "BigInt.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
        string num1;
        string num2;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        BigInt bignum1(num1);
        BigInt bignum2(num2);

        BigInt bignum_sum = bignum1 + bignum2;
        BigInt bignum_dif = bignum1 - bignum2;
        BigInt bignum_prod = bignum1 * bignum2;

        cout << "Sum: " << bignum_sum << endl;
        cout << "Difference: " << bignum_dif << endl;
        cout << "Product: " << bignum_prod << endl;

}