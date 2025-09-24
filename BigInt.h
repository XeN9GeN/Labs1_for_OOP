#ifndef BIGINT_H
#define BIGINT_H
#include<vector>
#include<string>
#include <iostream>

class BigInt
{
	std::vector<int> digits;
	int sign;

public:

	int get_sign() const {
		return sign;
	}
	void set_sign(int newSign) {
		sign = newSign;
	}


	BigInt(int n) {//под int
		if (n == 0) {
			digits.push_back(0);
			sign = 1;
			return;
		}

		if (n < 0) {
			sign = -1;
		}
		else {
			sign = 1;
		}
		
		int temp = n;
		while (temp != 0) {
			digits.insert(digits.begin(), temp % 10);
			temp /= 10;
		}			
	}
	BigInt(const std::string& str) {//под string
		sign = 1;
		bool f = false;

		for (char ch : str) {
			if(ch=='-' &&!f){
				sign = -1;
			}

			if (ch >= '0' && ch <= '9') {
				digits.push_back(ch - '0');
				f = true;
			}
		}
	}

	BigInt(const std::vector<int>& vec, int sgn) : digits(vec),sign(sgn) {
		while (digits.size() > 1 && digits[0] == 0) {
			digits.erase(digits.begin());
		}
	}
	


	friend std::ostream& operator<<(std::ostream& out, const BigInt& bi) {
		if (bi.sign == -1) {
			out << '-';
		}
		
		for (size_t i = 0; i < bi.digits.size(); ++i)
			out << bi.digits[i];

		return out;
	}



	friend bool operator==(const BigInt& ai, const BigInt& bi) {
		if (ai.digits.size() != bi.digits.size()) 
			return false;

		for (size_t i = 0; i < ai.digits.size(); ++i)
			if (ai.digits[i] != bi.digits[i]) 
				return false;

		return true;
	}

	friend bool operator>(const BigInt& a, const BigInt& b) {
		if (a.digits.size() > b.digits.size()) return true;
		if (a.digits.size() < b.digits.size()) return false;

		for (size_t i = 0; i < a.digits.size(); ++i) {
			if (a.digits[i] > b.digits[i]) return true;
			if (a.digits[i] < b.digits[i]) return false;
		}
		return false;
	}

	friend bool operator<(const BigInt& ai, const BigInt& bi) {
		if (ai.digits.size() < bi.digits.size()) return true;
		if (ai.digits.size() > bi.digits.size()) return false;

		for (size_t i = 0; i < ai.digits.size(); ++i) {
			if (ai.digits[i] < bi.digits[i]) return true;
			if (ai.digits[i] > bi.digits[i]) return false;
		}
		return false;
	}

	friend bool operator<=(const BigInt& ai, const BigInt& bi) {
		return (ai < bi) || (ai == bi);
	}

	friend bool operator>=(const BigInt& ai, const BigInt& bi) {
		return (ai > bi) || (ai == bi);
	}


	
	long size() const {
		return static_cast<long>(digits.size());
	}

	int operator[](int i) const {
		return digits[i];
	}

	int& operator[](int i) {
		return digits[i];
	}

	void insertion(int n) {
		digits.insert(digits.begin(), n);
	}

};

#endif


