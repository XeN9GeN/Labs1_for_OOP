#include "BigIntOperations.h"
#include "BigIntCompare.h"
#include "BigInt.h"
#include<algorithm>
#include <vector>
#include <string>

using namespace std;

int get_compare_sign(const BigInt& a, const BigInt& b) {
	if (a > b) {
		return 1;
	}
	else {
		return -1;
	}
}


BigInt BigIntOperations::op_plus(BigInt& a, BigInt& b) const{
	if (a.get_sign() == 1 && b.get_sign() == 1) {

		BigInt a_copy = a;
		BigInt b_copy = b;
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

	
	else if(a.get_sign() == -1 && b.get_sign() == -1){

		BigInt a_copy = a;
		BigInt b_copy = b;
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

	
	else if(a.get_sign()==1 && b.get_sign()==-1){
		return op_minus(a,b);
	}

	else{
		return op_minus(b,a);
	}
}


BigInt BigIntOperations::op_minus(BigInt& a, BigInt& b) const {
	BigInt a_copy = a;
	BigInt b_copy = b;
	add_nulls(a_copy, b_copy, a_copy.size(), b_copy.size());

	
	vector<int> res;
	int res_sign;

	if(a.get_sign()==-1 && b.get_sign()==1){
		a_copy.set_sign(1);
		BigInt temp = op_plus(a_copy,b_copy);
		temp.set_sign(-1);
		return temp;
	}

	if(a.get_sign()==1 && b.get_sign()==-1){
		b_copy.set_sign(1);
		return op_plus(a_copy,b_copy);
	}

	if(a.get_sign()==-1 && b.get_sign()==-1){
		swap(a_copy, b_copy);
		a_copy.set_sign(1);
		b_copy.set_sign(1);
	}
	
	if(get_compare_sign(a_copy, b_copy)==1){
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


BigInt BigIntOperations::op_mult(BigInt& a, BigInt& b) const {
	BigInt a_copy = a;
	BigInt b_copy = b;

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


BigInt BigIntOperations::op_div(BigInt& a, BigInt& b) const {
	BigInt a_copy = a;
	BigInt b_copy = b;

	

	if (a_copy < b_copy)
		return 0;

	BigInt count(0);
	BigInt one(1);
	//-15/5 15/-3 -15/-3
	while (a_copy >= b_copy) {
		a_copy = op_minus(a_copy, b_copy);
		cout <<"A cop: "<< a_copy << "\n";
		count = op_plus(count, one);
	}
	return count;
}

