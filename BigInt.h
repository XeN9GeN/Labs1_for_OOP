#pragma once
#include<vector>

class BigInt
{
	std::vector<int> digits;
	bool is_negative;

public:
	BigInt(int n) {
		int temp = n;

		while (temp != 0) {
			digits.insert(digits.begin(), temp % 10);
			temp /= 10;
		}			
	}
	
	long size() {
		return digits.size();
	}

	void insertion(int value) {
		digits.insert(digits.begin(), value);
	}

	int operator[](int i) {
		return digits[i];
	}

	BigInt(const std::vector<int>& d) : digits(d) {}
}; 


