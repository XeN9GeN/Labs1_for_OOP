#include "BigIntOperations.h"
#include "BigInt.h"
#include <vector>
#include<algorithm>
#include <string>
using namespace std;

BigIntOperations op_plus(BigInt& a, BigInt& b) {
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