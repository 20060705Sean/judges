#include<bits/stdc++.h>
using namespace std;

struct block{
	int sum = 0, dir = 4;
};

void debug(vector<vector<block>> a) {
	cout << endl;
	for (int i = 0;i < (int)a.size();i++) {
		for (int j = 0;j <(int)a[i].size();j++) {
			cout << a[i][j].sum << ',' << a[i][j].dir << '\t';
		}
		cout << endl;
	}
}

int main() {
	int i, j;string a, b;cin >> a >> b;
	vector<vector<block>> dp(a.size() + 1, vector<block>(b.size() + 1));
	// construct chart
	for (i = 0;i < (int)a.size();i++) {
		for (j = 0;j < (int)b.size();j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1].sum = dp[i][j].sum + 1;
				dp[i + 1][j + 1].dir = 0;
			} else if (dp[i][j + 1].sum >= dp[i + 1][j].sum) {
				dp[i + 1][j + 1].sum = dp[i][j + 1].sum;
				dp[i + 1][j + 1].dir = 1;
			} else {
				dp[i + 1][j + 1].sum = dp[i + 1][j].sum;
				dp[i + 1][j + 1].dir = 2;
			}
		}
	}
	//debug(dp);
	// Backtracking
	vector<char> result;int now_dir = dp[a.size()][b.size()].dir;
	i = a.size(), j = b.size();
	while (1) {
		if (now_dir == 0) {
			result.push_back(a[i - 1]);
			i--;j--;
		} else if (now_dir == 1) i--;
		else if (now_dir == 2) j--;
		else break;
		now_dir = dp[i][j].dir;
	}
	for (i = result.size() - 1;i >= 0;i--) printf("%c", result[i]);
	if (result.empty()) cout << 'E';
}
