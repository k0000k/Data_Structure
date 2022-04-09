#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ab(int k, int n, string ab_number) {
	int bit = k;
	char alphabets[2] = {'a', 'b'};
	string result = "";
	string _01 = "01";

	if (k == pow(2, n)) {
		return 0;
	}
	//cout << k << endl;

	while (bit > 0) {
		if (bit % 2 == 1) ab_number = "1" + ab_number;
		else ab_number = "0" + ab_number;
		bit >>= 1;
	}
	//cout << ab_number << endl;

	while (ab_number.length() < n) {
		ab_number = "0" + ab_number;
	}

	for (int count = 0; count < n; count++) {		
		if (ab_number.at(count) == _01.at(0)) {
			result.append("a");
		}
		else {
			result.append("b");
		}
	}

	cout << result << endl;
	ab_number = "";
	return ab(k+1, n, ab_number);
}

int main() {
	int n;
	int k = 0;
	string ab_number = "0";
	cin >> n;
	ab(k, n, ab_number);
	return 0;
}