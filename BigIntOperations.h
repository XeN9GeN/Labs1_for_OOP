#pragma once
#include"BigInt.h";
#include <vector>
#include<algorithm>
#include <string>


class BigIntOperations
{
	BigIntOperations op_plus(BigInt&a,BigInt&b) const;
	BigIntOperations op_minus(BigInt& a, BigInt& b) const;
	BigIntOperations op_mult(BigInt& a, BigInt& b) const;
	BigIntOperations op_div(BigInt& a, BigInt& b) const;
	
};

