#include "BigInt.h"
#include <vector>
#include <string>
#include <algorithm>

void add_nulls(BigInt& a, BigInt& b,  int size1, int size2) {
	int r = abs(size1 - size2);

	if (size1>=size2) {
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
