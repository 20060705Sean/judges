#include <bits/stdc++.h>
using namespace std;


int main() {
	int N, i;scanf("%d", &N);
	long long sum1 = 0, sum2 = 0;
	vector<int> A(N + 1);for (i = 1;i <= N;i++) scanf("%d", &A[i]);
	vector<vector<long long>> dp(N + 2, vector<long long>(2));
	dp[1][0] = 0;dp[1][1] = INT_MAX;
	for (i = 2;i <= N;i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + A[i];
	}
	sum1 = dp[N][1]	;
	dp[1][0] = INT_MAX;dp[1][1] = A[1];
	for (i = 2;i <= N;i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + A[i];
	}
	sum2 = min(dp[N][0], dp[N][1]);
	printf("%lld", min(sum1, sum2));
}
