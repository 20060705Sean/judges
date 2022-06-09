#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;scanf("%d", &n);
	long long m, q, i, j, sum = 0;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			m = i * j;
			q = sqrt(m);
			if (q * q == m) {
				if (i == j) sum++;
				else sum += 2;
			}
		}
	}
	printf("%lld", sum);
}
