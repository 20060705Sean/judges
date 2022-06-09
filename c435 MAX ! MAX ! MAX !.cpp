#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, j, n, m = 100001, M = 1;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%d", &j);
		if (j < m) m = j;
		if (j > M) M = j;
	}
	printf("%d", M - m);
	return 0;
}