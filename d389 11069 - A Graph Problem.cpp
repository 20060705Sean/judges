#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> k {0, 1, 2, 2, 3, 4};
	for (int i = 6;i < 77;i ++) {
		k.push_back(k[i - 2] + k[i - 3]);
	}
	unsigned int i;
	while (cin >> i) {
		cout << k[i] << endl;
	}
	return 0;
}