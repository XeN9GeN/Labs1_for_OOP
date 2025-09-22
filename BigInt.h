#pragma once
#include<vector>
#include<string>
#include <iostream>

class BigInt
{
	std::vector<int> digits;

public:
	BigInt(int n) {//под int
		int temp = n;

		while (temp != 0) {
			digits.insert(digits.begin(), temp % 10);
			temp /= 10;
		}			
	}

	BigInt(const std::string& str) {//под string
		for (char ch : str) {
			if (ch >= '0' && ch <= '9') {
				digits.push_back(ch - '0');
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const BigInt& bi) {
		for (size_t i = 0; i < bi.digits.size(); ++i)
			out << bi.digits[i];
		return out;
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
}; 


