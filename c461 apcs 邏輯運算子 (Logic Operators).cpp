#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {
		bool flag = false;
		if (a != 0) a = 1;
		if (b != 0) b = 1;
		if ((a & b) == c) {
			flag = true;
			cout << "AND" << endl;
		}
		if ((a | b) == c) {
			flag = true;
			cout << "OR" << endl;
		}
		if ((a ^ b) == c) {
			flag = true;
			cout << "XOR" << endl;
		}
		if (not flag) {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}