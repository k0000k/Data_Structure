#include "polynomial.h"

using namespace std;

void Polynomial::LoadPolynomial(std::string& filename) {
	ifstream ifs;
	ifs.open(filename);

	if (ifs.is_open()) {
		while (!ifs.eof()) {
			string str;
			int temp_num;
			vector<int> temp1;
			getline(ifs, str);
			stringstream stream(str);

			while (stream >> temp_num) {
				temp1.push_back(temp_num);
				if (first == true) {
					temp1.push_back(100);
					first = false;
				}
			}
			poly.push_back(temp1);
		}
		ifs.close();
	}
}

bool cmp1(vector<int> a, vector<int> b)
{
	return a[1] > b[1];
};

bool cmp2(vector<int> a, vector<int> b)
{
	return a[0] > b[0];
};

void Polynomial::PrintPolynomial() {
	sort(poly.begin(), poly.end(), &cmp1);
	poly[0][0] = poly.size() - 1;

	for (int i = 1; i <= poly[0][0]; i++) {
		for (int j = 0; j <= 1; j++) {
			cout << poly[i][j] << " ";
		}
		cout << endl;
	}
}

void Polynomial::add(Polynomial a, Polynomial b) {
	for (int k = 0; k <= a.poly[0][0]; k++) {
		poly.push_back({ a.poly[k][0] ,a.poly[k][1] });
	}


	for (int i = 1; i <= b.poly[0][0]; i++) {
		bool endflag = true;
		for (int j = 1; j <= poly[0][0]; j++) {
			if (b.poly[i][1] == poly[j][1]) {
				poly[j][0] = poly[j][0] + b.poly[i][0];
				endflag = false;
				break;
			}
		}
		if (endflag == false) {
			continue;
		}
		poly.push_back({b.poly[i][0],b.poly[i][1] });
	}

	sort(poly.begin(), poly.end(), &cmp2);

	while (poly[poly.size() - 1][0] == 0) {
		poly.pop_back();
	}
}