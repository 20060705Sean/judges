#include<bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b, long long c) {
	return (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
}

int main() {
	long long k, n, i, sum;
	while (scanf("%lld", &k) != EOF) {
		i = solve(1, 1, -abs(k));
		sum = i * (i + 1) / 2;
		while (1) {
			if ((k - sum) % 2 == 0) {
				if (sum >= abs(k)) {
					if ((k - sum) / 2 <= i) {
						printf("%lld\n", i);
						break;
					}
				}
			}
			i++;
			sum += i;
		}
	}
}
