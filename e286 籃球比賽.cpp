#include <bits/stdc++.h>
using namespace std;

bool first, second;
int a = 0, b = 0, k, i;
int main() {
	for (i = 0;i < 4;i++) {
		cin >> k;
		a += k;
	}
	for (i = 0;i < 4;i++) {
		cin >> k;
		b += k;
	}
	first = a > b;
	cout << a << ':' << b << endl;
	a = 0;
	b = 0;
	for (i = 0;i < 4;i++) {
		cin >> k;
		a += k;
	}
	for (i = 0;i < 4;i++) {
		cin >> k;
		b += k;
	}
	cout << a << ':' << b << endl;
	second = a > b;
	if (first != second) cout << "Tie";
	else if (first == second) {
		if (first == 1) cout << "Win";
		else cout << "Lose";
	}
}