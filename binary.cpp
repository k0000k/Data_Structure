#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <tuple>

using namespace std;

tuple<int, int> binary(vector<int> num, int target, int start, int end) {
	int count = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		count += 1;

		if (num[mid] == target) {
			return tuple<int, int>(mid, count);
		}

		else if (num[mid] >= target) {
			end = mid - 1;
		}

		else {
			start = mid + 1;
		}
	}

	return tuple<int, int>(-1, count);
}

int main() {
	int n, target, temp_num;
	string temp;
	vector<int> num;

	cin >> n;
	cin.ignore(); //표준 입력 버퍼에 남은 \n clear
	getline(cin, temp);
	cin >> target;

	stringstream stream1(temp);

	while (stream1 >> temp_num) {
		num.push_back(temp_num);
	}

	tuple<int, int> result = binary(num, target, 0, num.size() - 1);

	cout << get<0>(result) << endl;
	cout << get<1>(result) << endl;
	return 0;
}