#include <iostream>
using namespace std;

int combination(int n, int r) {
	if (n == r) {
		return 1;
	}

	else if (r == 1) {
		return n;
	}

	return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() {
	int n, r, result;
	cin >> n >> r;

	result = combination(n, r);

	cout << result << endl;
}