#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, sum;
	cin >> a >> b;
	sum = (b - a) / 4 + 1;
	sum -= 2 * (b / 100 - a / 100);
	sum += 2 * (b / 400 - a / 400);
	cout << sum;
	return 0;
}