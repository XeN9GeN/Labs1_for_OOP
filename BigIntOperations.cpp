#include "BigInt.h"
#include<algorithm>
#include <vector>
#include <string>

using namespace std;
void add_nulls(BigInt& a, BigInt& b, int size1, int size2) {
	int r = abs(size1 - size2);

	if (size1 >= size2) {
		while (r > 0) {
			b.insertion(0);
			r--;
		}
	}
	else {
		while (r > 0) {
			a.insertion(0);
			r--;
		}
	}
}

BigInt BigInt::operator+(const BigInt& other)const  {
	if (this->get_sign() == 1 && other.get_sign() == 1) {

		BigInt a_copy = *this;
		BigInt b_copy = other;
		add_nulls(a_copy, b_copy, a_copy.size(), b_copy.size());

		vector<int> res;
		int cf = 0;

		for (int i = a_copy.size() - 1; i >= 0; i--) {
			int sum = a_copy[i] + b_copy[i] + cf;
			res.insert(res.begin(), sum % 10);
			cf = sum / 10;
		}

		if (cf > 0) {
			res.insert(res.begin(), cf);
		}

		while (res.size() > 1 && res[0] == 0) {
			res.erase(res.begin());	
		}

		return BigInt(res, 1);
	}


	else if (this->get_sign() == -1 && other.get_sign() == -1) {

		BigInt a_copy = *this;
		BigInt b_copy = other;
		add_nulls(a_copy, b_copy, a_copy.size(), b_copy.size());

		vector<int> res;

		int cf = 0;
		for (int i = a_copy.size() - 1; i >= 0; i--) {
			int sum = a_copy[i] + b_copy[i] + cf;
			res.insert(res.begin(), sum % 10);
			cf = sum / 10;
		}

		if (cf > 0) {
			res.insert(res.begin(), cf);
		}

		while (res.size() > 1 && res[0] == 0) {
			res.erase(res.begin());
		}

		return BigInt(res, -1);
	}

	
	else if(this->get_sign()==1 && other.get_sign()==-1){
		BigInt positive_other = other;
		positive_other.set_sign(1);
		return *this - positive_other;
	}

	else{
		BigInt positive_this = *this;
		positive_this.set_sign(1);
		return other - positive_this;
	}
}
BigInt BigInt::operator-(const BigInt& other)const {
	BigInt a_copy =*this;
	BigInt b_copy = other;
	add_nulls(a_copy, b_copy, a_copy.size(), b_copy.size());

	
	vector<int> res;
	int res_sign;

	if(this->get_sign() == -1 && other.get_sign() == 1) {
		a_copy.set_sign(1);
		BigInt temp = a_copy + other;
		temp.set_sign(-1);
		return temp;
	}

	if(this->get_sign()==1 && other.get_sign()==-1){
		b_copy.set_sign(1);
		return *this + other;
	}

	if(this->get_sign()==-1 && other.get_sign()==-1){
		swap(a_copy, b_copy);
		a_copy.set_sign(1);
		b_copy.set_sign(1);
	}
	
	if(a_copy>b_copy){
		res_sign = 1;
	}
	else{
		res_sign = -1;
		swap(a_copy, b_copy);
	}


	int cf = 0;
	int s = a_copy.size();
	for (int i = s - 1; i >= 0; i--) {
		int diff = a_copy[i] - b_copy[i] - cf;
		if (diff < 0) {
			diff += 10;
			cf = 1;
		}
		else
			cf = 0;
		res.insert(res.begin(), diff);

	}

	while (res.size() > 1 && res[0] == 0) {
		res.erase(res.begin());
	}

	if (res.size() == 1 && res[0] == 0) {
		res_sign = 1;
	}
	
	return BigInt(res,res_sign);
	
}
BigInt BigInt::operator*(const BigInt& other)const {
	BigInt a_copy = *this;
	BigInt b_copy = other;

	int n = a_copy.size();
	int m = b_copy.size();
	vector<int> res(n + m, 0);

	if ((a_copy.get_sign() == 1 && b_copy.get_sign() == 1)|| (a_copy.get_sign() == -1 && b_copy.get_sign() == -1)) {

		for (int i = n - 1; i >= 0; i--) {
			int c = 0;
			for (int j = m - 1; j >= 0; j--) {
				int sum = res[i + j + 1] + a_copy[i] * b_copy[j] + c;
				res[i + j + 1] = sum % 10;
				c = sum / 10;
			}
			res[i] += c;
		}

		while (res.size() > 1 && res[0] == 0) {
			res.erase(res.begin());
		}

		return BigInt(res, 1);
	}


	else if ((a_copy.get_sign() == 1 && b_copy.get_sign() == -1) || (a_copy.get_sign() == -1 && b_copy.get_sign() == 1)) {
		
		for (int i = n - 1; i >= 0; i--) {
			int c = 0;
			for (int j = m - 1; j >= 0; j--) {
				int sum = res[i + j + 1] + a_copy[i] * b_copy[j] + c;
				res[i + j + 1] = sum % 10;
				c = sum / 10;
			}
			res[i] += c;
		}

		while (res.size() > 1 && res[0] == 0) {
			res.erase(res.begin());
		}

		return BigInt(res, -1);
	}
}
BigInt BigInt::operator/(const BigInt& other)const {
	BigInt a_copy = *this;
	BigInt b_copy = other;
	BigInt count(0);
	BigInt one(1);
	bool f = true;

	if (a_copy.get_sign() == 1 && b_copy.get_sign() == 1) {// 10/5
		if (a_copy < b_copy) return 0;
	}
	if (a_copy.get_sign() == -1 && b_copy.get_sign() == -1) {// -10/-5
		a_copy.set_sign(1);
		b_copy.set_sign(1);
		if (a_copy > b_copy){}
		else return 0;
	}
	if (a_copy.get_sign() == -1 && b_copy.get_sign() == 1) {// -10/5
		a_copy.set_sign(1);
		if (a_copy > b_copy) { count.set_sign(-1); }
		else return 0;
	}
	else { // 10/-2
		b_copy.set_sign(1);
		if (a_copy > b_copy) { count.set_sign(-1); }
		else return 0;
	}
	
	if (b_copy.size() == 1 && b_copy[0] == 0) throw invalid_argument("Division by zero is not allowed.");
	if (a_copy == b_copy) return one;

	while (a_copy >= b_copy) {
		a_copy = a_copy-b_copy;
		count = count + one;
	}
	return count;
}

BigInt& BigInt::operator++() { //++a
	*this = *this + BigInt(1);
	return *this;
}
BigInt& BigInt::operator--() {
	*this = *this - BigInt(1);
	return *this;
}
BigInt BigInt::operator++(int) { //a++
	BigInt temp = *this;
	*this = *this + BigInt(1);
	return temp;
}
BigInt BigInt::operator--(int) {
	BigInt temp = *this;
	*this = *this - BigInt(1);
	return temp;
}

BigInt& BigInt::operator+=(const BigInt& other) {
	*this = *this + other;
	return *this;
}
BigInt& BigInt::operator-=(const BigInt& other) {
	*this = *this - other;
	return *this;
}
BigInt& BigInt::operator*=(const BigInt& other) {
	*this = *this * other;
	return *this;
}
BigInt& BigInt::operator/=(const BigInt& other) {
	*this = *this * other;
	return *this;
}

ostream& operator<<(ostream& out, const BigInt& bi) {
	if (bi.sign == -1) {
		out << '-';
	}

	for (size_t i = 0; i < bi.digits.size(); ++i)
		out << bi.digits[i];

	return out;
}

bool operator==(const BigInt&a, const BigInt& b) {
	BigInt ai = a;
	ai.set_sign(1);
	BigInt bi = b;
	bi.set_sign(1);

	if (ai.digits.size() != bi.digits.size()) return false;

	for (size_t i = 0; i < ai.digits.size(); ++i)
		if (ai.digits[i] != bi.digits[i]) return false;

	return true;
}
bool operator>(const BigInt& a, const BigInt& b) {
	if (a.get_sign() == 1 && b.get_sign() == -1) return true;
	if (a.get_sign() == -1 && b.get_sign() == 1) return false;

	if (a.get_sign() == 1 && b.get_sign() == 1) {
		if (a.digits.size() > b.digits.size()) return true;
		if (a.digits.size() < b.digits.size()) return false;

		for (size_t i = 0; i < a.digits.size(); ++i) {
			if (a.digits[i] > b.digits[i]) return true;
			if (a.digits[i] < b.digits[i]) return false;
		}
	}
	else {
		if (a.digits.size() < b.digits.size()) return true;
		if (a.digits.size() > b.digits.size()) return false;

		for (size_t i = 0; i < a.digits.size(); ++i) {
			if (a.digits[i] < b.digits[i]) return true;
			if (a.digits[i] > b.digits[i]) return false;
		}
	}
	return false;
}
bool operator<(const BigInt& a, const BigInt& b) {
	if (a.get_sign() == -1 && b.get_sign() == 1) return true;
	if (a.get_sign() == 1 && b.get_sign() == -1) return false;

	if (a.get_sign() == 1 && b.get_sign() == 1) {
		if (a.digits.size() < b.digits.size()) return true;
		if (a.digits.size() > b.digits.size()) return false;

		for (size_t i = 0; i < a.digits.size(); ++i) {
			if (a.digits[i] < b.digits[i]) return true;
			if (a.digits[i] > b.digits[i]) return false;
		}
	}
	else {
		if (a.digits.size() > b.digits.size()) return true;
		if (a.digits.size() < b.digits.size()) return false;

		for (size_t i = 0; i < a.digits.size(); ++i) {
			if (a.digits[i] > b.digits[i]) return true;
			if (a.digits[i] < b.digits[i]) return false;
		}
	}
	return false;
}
bool operator<=(const BigInt& a, const BigInt& b) {
	return (a < b) || (a == b);
}
bool operator>=(const BigInt& a, const BigInt& b) {
	return (a > b) || (a == b);
}
