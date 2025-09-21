#pragma once
#include<vector>;

class BigInt
{
	std::vector<int> digits;
	long size=0;

public:
	BigInt(int n) {
		int temp1 = n;

		while (temp1 != 0) {
			digits.insert(digits.begin(), temp1 % 10);
			size++;
			temp1 /= 10;
		}				 
	}
	
	BigInt(const std::vector<int>& d) : digits(d),size(d.size()) {}
}; 


