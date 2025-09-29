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
			n = -n;
			
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
	BigInt(const std::string& str) {
		sign = 1;
		bool digit_started = false;

		for (char ch : str) {
			if (ch == '-' && !digit_started) { sign = -1; }
			else if (ch == '+' && !digit_started) { sign = 1; }
			else if (ch >= '0' && ch <= '9') {
				digits.push_back(ch - '0');
				digit_started = true;
			}
			else if (ch != ' ' && digit_started) { break; }
		}
		if (digits.empty()) {
			digits.push_back(0);
			sign = 1;
		}
		while (digits.size() > 1 && digits[0] == 0) {
			digits.erase(digits.begin());
		}
	}
	BigInt(const std::vector<int>& vec, int sgn) : digits(vec),sign(sgn) {
		while (digits.size() > 1 && digits[0] == 0) {
			digits.erase(digits.begin());
		}
	}
	

	BigInt operator+(const BigInt& other) const;
	BigInt operator-(const BigInt& other) const;
	BigInt operator*(const BigInt& other) const;
	BigInt operator/(const BigInt& other) const;
	
	BigInt& operator=(const BigInt& other);
	BigInt& operator+=(const BigInt& other);
	BigInt& operator-=(const BigInt& other);
	BigInt& operator*=(const BigInt& other);
	BigInt& operator/=(const BigInt& other);

	BigInt& operator++();//++a
	BigInt& operator--();//--a
	BigInt  operator++(int);//a++
	BigInt  operator--(int);//a--
	BigInt  operator-() const {
		BigInt temp = *this;
		if (temp != BigInt(0)) { temp.set_sign(-temp.get_sign()); }
		return temp;
	}
	


	friend bool operator==(const BigInt& a, const BigInt& b);
	friend bool operator!=(const BigInt & a, const BigInt & b);
	friend bool operator> (const BigInt& a, const BigInt& b);
	friend bool operator< (const BigInt& a, const BigInt& b);
	friend bool operator<=(const BigInt& a, const BigInt& b);
	friend bool operator>=(const BigInt& a, const BigInt& b);
	


	long size() const { return static_cast<long>(digits.size()); }
	void insertion(int n) { digits.insert(digits.begin(), n); }

	friend std::ostream& operator<<(std::ostream& out, const BigInt& bi);
	operator std::string() const {
		std::string str;
		if (sign == -1) {
			str += '-';
		}
		for (size_t i = 0; i < digits.size(); ++i) {
			str += std::to_string(digits[i]);
		}
		return str;
	}

	int operator[](int i) const { return digits[i]; }
	int& operator[](int i) { return digits[i]; }	
};


BigInt operator+(int left, const BigInt& right);
BigInt operator-(int left, const BigInt& right);
BigInt operator*(int left, const BigInt& right);
BigInt operator/(int left, const BigInt& right);

bool operator==(int left, const BigInt& right);
bool operator!=(int left, const BigInt& right);
bool operator> (int left, const BigInt& right);
bool operator< (int left, const BigInt& right);
bool operator<=(int left, const BigInt& right);
bool operator>=(int left, const BigInt& right);




#endif


