#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;

bool comparesion_for_nulls(int a, int b) {
	return a > b;
}

bool comparesion_for_vector(vector <int>& num1, vector <int>& num2) {
	if (num1.size() != num2.size()) {
		return num1.size() >= num2.size();
	}

	int s = num1.size();
	for (int i = 0; i < s; i++) {
		if (num1[i] != num2[i]) {
			return num1[i] > num2[i];
		}
	}
	return false;
}


vector<int> slozhenie(vector<int>& first_num, vector<int>& second_num) {
	vector<int> res;
	int cf = 0;

	for (int i = first_num.size() - 1; i >= 0; i--) {
		int sum = first_num[i] + second_num[i] + cf;
		res.insert(res.begin(), sum % 10);
		cf = sum / 10;
	}

	if (cf > 0) {
		res.insert(res.begin(), cf);
	}

	return res;
}

vector<int> minuselo(vector<int>& num1, vector<int>& num2) {
	vector<int> res;
	bool flag = false;
	
	if (!comparesion_for_vector(num1, num2)) {
		swap(num1, num2);
		flag = true;
	}

	int cf = 0;
	int s = num1.size();
	for (int i = s - 1; i >= 0; i--) {
		int diff = num1[i] - num2[i] - cf;
		if (diff <  0) {
			diff += 10; 
			cf = 1;
		}
		else
			cf = 0;
		res.insert(res.begin(), diff);
		
	}
	if (flag) {
		res.insert(res.begin(), -1);//минус
	}

	return res;
}



int main() {
	int n, m;
	vector<int>num1, num2;
	
	cout << "First num: ";
	cin >> n;
	cout << "Second num: ";
	cin >> m;

	int size1=0, size2=0;
	int temp1 = n, temp2 = m;

	while (temp1 != 0) {
		num1.insert(num1.begin(), temp1 % 10);
		size1++;
		temp1 /= 10;
	}
	while (temp2 != 0) {
		num2.insert(num2.begin(), temp2 % 10);
		size2++;
		temp2 /= 10;
	}

	int r = abs(size1 - size2);
	if (comparesion_for_nulls(size1, size2)) {
		while (r > 0) {
			num2.insert(num2.begin(), 0);
			r--;
		}
	}
	else {
		while (r > 0) {
			num1.insert(num1.begin(), 0);
			r--;
		}
	}

	vector<int> res = minuselo(num1, num2);
	cout << "Answer: ";
	if (res[0] == -1) {
		cout << "-";
		for (int i = 1; i < res.size(); i++) {
			cout << res[i];
		}
	}
	else {
		for (int i : res) {
			cout << i;
		}
	}
	return 0;
}
