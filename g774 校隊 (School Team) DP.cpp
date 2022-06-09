	#include <bits/stdc++.h>
	using namespace std;

	int main() {
		// vars and inputs
		int N, M, i, j, boy, girl;
		cin >> N >> M;
		vector<int> girl_speed, boy_speed;
		vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
		for (i = 0;i < N + M;i++) {
			cin >> boy >> girl;
			girl_speed.push_back(girl);
			boy_speed.push_back(boy);
		}
		// calculation
		for (i = 1;i <= N;i++) dp[i][0] = dp[i - 1][0] + boy_speed[i - 1];
		for (i = 1;i <= M;i++) dp[0][i] = dp[0][i - 1] + girl_speed[i - 1];
		for (i = 1;i <= N;i++) {
			for (j = 1;j <= M;j++) {
				dp[i][j] = min(dp[i - 1][j] + boy_speed[i + j - 1], dp[i][j - 1] + girl_speed[i + j - 1]);
			}
	 	}
		// output
		cout << dp[N][M];
		return 0;
	}