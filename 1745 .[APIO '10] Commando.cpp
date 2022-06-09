#include<bits/stdc++.h>
using namespace std;

/*
S := prefix_sum
dp[i] = max(
	dp[i - 1] + f(S[i] - S[i - 1]),
	dp[i - 2] + f(S[i] - S[i - 2]),
	...
	dp[1] + f(S[i] - S[1]),
	dp[0] + f(S[i] - S[0])
)
= max{j < i}(dp[j] + f(S[i] - S[j]))
= max{j < i}(dp[j] + a * (S[i] - S[j])^2 + b * (S[i] - S[j]) + c)
= max{j < i}(dp[j] + a * (S[i]^2 - 2*S[i]*S[j] + S[j]^2) + b * (S[i] - S[j]) + c)
= f(S[i]) + max{j < i}(dp[j] - 2aS[i]S[j] + a * S[j]^2 + b * S[j] + c - 2b * S[j] - c)
= f(S[i]) + max{j < i}(dp[j] - 2aS[i]S[j] + f(S[j]) - 2bS[j] - c)
= f(S[i]) + max{j < i}(-2S[j](aS[i] + b) + (dp[j] + f(S[j]) - c))
*/

vector<long long> prefix_sum(vector<long long> origin) {
	int n = origin.size();vector<long long> new_vec = {0};
	for (int i = 0;i < n;i++) new_vec.push_back(new_vec[i] + origin[i]);
	return new_vec;
}

void debug(vector<long long> a) {
	cout << endl;
	for (int i = 0;i < (int)a.size();i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	int n, i, j;long long a, b, c, big, temp;scanf("%d%lld%lld%lld", &n, &a, &b, &c);
	auto f = [a, b, c](long long x){return a * x * x + b * x + c;};
	vector<long long> x(n), S, dp(n + 1);for (i = 0;i < n;i++) scanf("%lld", &x[i]);S = prefix_sum(x);
	vector<bool> possible(n);
	for (i = 0;i < n;i++) {
		big = -LONG_LONG_MAX;
		for (j = 0;j <= i;j++) {
			temp = dp[j] + f(S[i + 1] - S[j]);
			if (temp > big) big = temp;
		}
		dp[i + 1] = big;
	}
	printf("%lld", dp[n]);
}
