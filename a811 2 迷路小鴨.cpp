#include <iostream>
#include <cmath>
using namespace std;

long long GCD(long long a, long long b) {
	long long t;
	while (b) {
		t = a;
		a = b;
		b = t % b;
	}
	return a;
}

int main() {
	cin.sync_with_stdio(false), cin.tie(0);
	long long gcd, b1, b2;
	int t, amount;cin >> t;
	while (t--) {
		cin >> amount >> b1 >> b2, gcd = abs(b2 - b1);
		for (int i = 2; i < amount; ++i) cin >> b2, gcd = GCD(gcd, abs(b2 - b1));
		cout << gcd << '\n';
	}
}
