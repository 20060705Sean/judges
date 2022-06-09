#include<bits/stdc++.h>
using namespace std;

/*
dp[weight][item] = max(dp[weight][item - 1], p[i] + dp[weight - w[item]][item - 1])
*/

void debug(vector<vector<int>> a) {
	for (int i = 0;i < (int)a.size();i++) {
		for (int j = 0;j < (int)a[i].size();j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	int i, j, n, w, p;
	while (scanf("%d", &n) != EOF) {
		vector<vector<int>> dp(101, vector<int>(n, 0));
		scanf("%d%d", &w, &p);
		for (i = w;i < 101;i++) dp[i][0] = p;
		for (i = 1;i < n;i++) {
			scanf("%d%d", &w, &p);
			for (j = 0;j < w;j++) dp[j][i] = dp[j][i - 1];
			for (j = w;j < 101;j++) {
				dp[j][i] = max(dp[j][i - 1], p + dp[j - w][i - 1]);
			}
		}
		debug(dp);
		printf("%d\n", dp[100][n - 1]);
	}
}
