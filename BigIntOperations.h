#ifndef BIGINTOPERATIONS_H
#define BIGINTOPERATIONS_H
#include"BigInt.h"
#include <vector>
#include<algorithm>
#include <string>


class BigIntOperations
{
public:
	BigInt op_plus(BigInt&a,BigInt&b) const;
	BigInt op_minus(BigInt& a, BigInt& b) const;
	BigInt op_mult(BigInt& a, BigInt& b) const;
	BigInt op_div(BigInt& a, BigInt& b) const;
	
};

#endif