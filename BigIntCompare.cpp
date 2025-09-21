#include "BigInt.h"
#include <vector>
#include <string>
#include <algorithm>

bool compare_for_add_nulls(int& a, int& b) {
	return a > b;
}

bool compare_for_vector(BigInt& a, BigInt& b){
	if (a.size() != b.size()) {
		return a.size() >= b.size();
	}

	int s = a.size();
	for (int i = 0; i < s; i++) {
		if (a[i] != b[i]) {
			return a[i] > b[i];
		}
	}
	return false;
}


void add_nulls(BigInt& a, BigInt& b,  int size1, int size2) {
	int r = abs(size1 - size2);

	if (compare_for_add_nulls(size1, size2)) {
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