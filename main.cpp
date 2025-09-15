#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;

bool comparesion_for_null(int a, int b) {
	return a > b;
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

bool comparesion_for_vector(vector <int>&num1,)








int minus(vector<int>& first_num, vector<int>& second_num) {
	
}

int main() {
	int n, m;
	vector<int>first_num, second_num;
	
	cout << "First num: ";
	cin >> n;
	cout << "Second num: ";
	cin >> m;

	int c1=0, c2=0;
	int temp1 = n, temp2 = m;

	while (temp1 != 0) {
		first_num.insert(first_num.begin(), temp1 % 10);
		c1++;
		temp1 /= 10;
	}
	while (temp2 != 0) {
		second_num.insert(second_num.begin(), temp2 % 10);
		c2++;
		temp2 /= 10;
	}

	int r = abs(c1 - c2);
	if (comparesion_for_null(c1,c2)) {
		do {
			second_num.insert(second_num.begin(),0);
			r--;
		} while (r > 0);
	}
	else {
		do {
			first_num.insert(first_num.begin(), 0);
			r--;
		} while (r > 0);
	}





	for (int i : first_num) {
		cout << i << " ";
	}
	cout << endl;
	for (int i : second_num) {
		cout << i << " ";
	}
	return 0;
}
