#include <bits/stdc++.h>
using namespace std;

int main() {
	// vars and inputs
	int a, b, i, k, number_of_customers, total = 0, tempa, tempb;
	cin >> a >> b >> number_of_customers;
	for (i = 0;i < number_of_customers;i++) {
		tempa = 0;tempb = 0;
		while (cin >> k) {
			if (k == a) tempa++;
			else if (k == b) tempb++;
			else if (k == -a) tempa--;
			else if (k == -b) tempb--;
			else if (k == 0) break;
		}
		if (tempa > 0 and tempb > 0) total++;
	}
	// calculations
	// outputs
	cout << total;
	return 0;
}