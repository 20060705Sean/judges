#include <bits/stdc++.h>
using namespace std;

long long calculate(long long n) {
	return (n / 2 + 1) * (n / 2) / 2 + n / 2 + 1;
}

int main() {
	long long n;
	while (scanf("%lld", &n) != EOF) {
		printf("%lld\n", calculate((n % 2)?n - 1:n));
	}
}
