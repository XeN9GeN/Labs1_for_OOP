#include "BigIntOperations.h"
#include "BigIntCompare.h"
#include "BigInt.h"
#include<algorithm>
#include <vector>
#include <string>

using namespace std;


BigInt op_plus(BigInt& a, BigInt& b) {
	vector<int> res;
	int cf = 0;

	for (int i = a.size() - 1; i >= 0; i--) {
		int sum = a[i] + b[i] + cf;
		res.insert(res.begin(), sum % 10);
		cf = sum / 10;
	}

	if (cf > 0) {
		res.insert(res.begin(), cf);
	}

	return BigInt(res);
}


BigInt op_minus(BigInt& a, BigInt& b) {
	vector<int> res;
	bool flag = false;

	if (!compare_for_vector(a,b)) {
		swap(a, b);
		flag = true;
	}

	int cf = 0;
	int s = a.size();
	for (int i = s - 1; i >= 0; i--) {
		int diff = a[i] - b[i] - cf;
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

	if (flag) {
		res.insert(res.begin(), -1);//минус
	}
	return BigInt(res);
}


BigInt op_mult(BigInt& a, BigInt& b) {
	int n = a.size();
	int m = b.size();
	vector<int> res(n + m, 0);

	for (int i = n - 1; i >= 0; i--) {
		int c = 0;
		for (int j = m - 1; j >= 0; j--) {
			int sum = res[i + j + 1] + a[i] * b[j] + c;
			res[i + j + 1] =sum% 10;
			c = sum / 10;
		}
		res[i] += c;
	}

	while (res.size() > 1 && res[0] == 0) {
		res.erase(res.begin());
	}
	
	return BigInt(res);
}


BigInt op_div(BigInt& a, BigInt& b) {
	int count = 0;
	while (compare_for_vector(a,b)) {
		op_minus(a, b);
		count++;
	}
	
	return BigInt(count);
}