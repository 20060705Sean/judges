#include<bits/stdc++.h>
using namespace std;

/*
rolling
dp[i] = max(dp[i], p + dp[i - w])
*/

int main() {
	int i, j, n, w, p;
	vector<int> dp(101);
	while (scanf("%d", &n) != EOF) {
		scanf("%d%d", &w, &p);
		for (i = 0;i < w;i++) dp[i] = 0;
		for (i = w;i < 101;i++) dp[i] = p;
		for (i = 1;i < n;i++) {
			scanf("%d%d", &w, &p);
			for (j = 100;j >= w;j--) dp[j] = max(dp[j], dp[j - w] + p);
		}
		printf("%d\n", dp[100]);
	}
}

