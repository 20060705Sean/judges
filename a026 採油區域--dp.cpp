#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void debug_vec(vi a) {
	cout << endl;
	for (int i = 0;i < (int)a.size();i++) {
		cout << a[i] << ' ';
		
	}
	cout << endl;
}
void debug_2dvec(vvi a) {
	cout << endl;
	for (int i = 0;i < (int)a.size();i++) {
		for (int j = 0;j < (int)a[i].size();j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
vvi prefix_sum(vvi value) {
	vvi sum = value;
	int i, j, m = value.size(), n = value[0].size();
	for (i = 1;i < m;i++) {sum[i][0] += sum[i - 1][0];}
	for (i = 1;i < n;i++) {sum[0][i] += sum[0][i - 1];}
	for (i = 1;i < m;i++) {
		for (j = 1;j < n;j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + value[i][j];
		}
	}
	return sum;
}
void calculate_sq_val(vvi& s, vvi sum, int K) {
	int i, j, m = s.size(), n = s[0].size();
	s[K - 1][K - 1] = sum[K - 1][K - 1];
	for (i = K;i < m;i++) {
		s[i][K - 1] = sum[i][K - 1] - sum[i - K][K - 1];
	}
	for (i = K;i < n;i++) {
		s[K - 1][i] = sum[K - 1][i] - sum[K - 1][i - K];
	}
	for (i = K;i < m;i++) {for (j = K;j < n;j++) {
		s[i][j] = sum[i][j] - sum[i - K][j] - sum[i][j - K] + sum[i - K][j - K];
	}}
}
void calculate_max(vvi&ul, vvi&dl, vvi&ur, vvi&dr, vvi s, vi &r, vi &c, int K){
	int i, j, m = s.size(), n = s[0].size();
	ul[K - 1][K - 1] = s[K - 1][K - 1];
	for (i = K;i < m;i++) {ul[i][K - 1] = max(ul[i - 1][K - 1], s[i][K - 1]);}
	for (i = K;i < n;i++) {ul[K - 1][i] = max(ul[K - 1][i - 1], s[K - 1][i]);}
	for (i = K;i < m;i++) {for (j = K;j < n;j++) {ul[i][j] = max(max(ul[i - 1][j], ul[i][j - 1]), s[i][j]);}}
	dl[m - K][K - 1] = s[m - 1][K - 1];
	for (i = m - K - 1;i >= 0;i--) {dl[i][K - 1] = max(dl[i + 1][K - 1], s[i + K - 1][K - 1]);}
	for (i = K;i < n;i++) {dl[m - K][i] = max(dl[m - K][i - 1], s[m - 1][i]);}
	for (i = m - K;i >= 0;i--) {for (j = K;j < n;j++) {dl[i][j] = max(max(dl[i + 1][j], dl[i][j - 1]), s[i + K - 1][j]);}}
	ur[K - 1][n - K] = s[K - 1][n - 1];
	for (i = n - K - 1;i >= 0;i--) {ur[K - 1][i] = max(ur[K - 1][i + 1], s[K - 1][i + K - 1]);}
	for (i = K;i < m;i++) {ur[i][n - K] = max(ur[i - 1][n - K], s[i][n - 1]);}
	for (i = K;i < m;i++) {for (j = n - K;j >= 0;j--) {ur[i][j] = max(max(ur[i - 1][j], ur[i][j + 1]), s[i][j + K - 1]);}}
	dr[m - K][n - K] = s[m - 1][n - 1];
	for (i = m - K - 1;i >= 0;i--) {dr[i][n - K] = max(dr[i + 1][n - K], s[i + K - 1][n - 1]);}
	for (i = n - K - 1;i >= 0;i--) {dr[m - K][i] = max(dr[m - K][i + 1], s[m - 1][i + K - 1]);}
	for (i = m - K;i >= 0;i--) {for (j = n - K - 1;j >= 0;j--) {dr[i][j] = max(max(dr[i + 1][j], dr[i][j + 1]), s[i + K - 1][j + K - 1]);}}
	for (i = K - 1;i < m;i++) {for (j = K - 1;j < n;j++) {r[i] = max(r[i], s[i][j]);}}
	for (i = K - 1;i < n;i++) {for (j = K - 1;j < m;j++) {c[i] = max(c[i], s[j][i]);}}
}
int main_dp(vvi ul, vvi dl, vvi ur, vvi dr, vi r, vi c, int K) {
	int i, j, m = ul.size(), n = ul[0].size(), maxim = 0;
	vi val(4);
	vi::iterator a = val.begin(), b = val.end();
	for (i = K - 1;i < m - K;i++) {for (j = K - 1;j < n - K;j++) {
		val[0] = ul[i][j];
		val[1] = ur[i][j + 1];
		val[2] = dl[i + 1][j];
		val[3] = dr[i + 1][j + 1];
		sort(a, b);
		maxim = max(maxim, val[3] + val[2] + val[1]);
	}}
	for (i = 2 * K - 1;i < m - K;i++) {
		maxim = max(maxim, ul[i - K][n - 1] + r[i] + dl[i + 1][n - 1]);
	}
	for (i = 2 * K - 1;i < n - K;i++) {
		maxim = max(maxim, ul[m - 1][i - K] + c[i] + ur[m - 1][i + 1]);
	}
	return maxim;
}
int main() {
	int M, N, K, i, j;
	scanf("%d%d%d", &M, &N, &K);
	vvi oil(M, vi(N, 0)), left_up(M, vi(N)), left_down(M, vi(N)), right_up(M, vi(N)), 
		right_down(M, vi(N)), s(M, vi(N)), sum(M, vi(N));
	vi row(M), column(N);
	for (i = 0;i < M;i++) {for (j = 0;j < N;j++) {scanf("%d", &oil[i][j]);}}
	sum = prefix_sum(oil);
	calculate_sq_val(s, sum, K);
	calculate_max(left_up, left_down, right_up, right_down, s, row, column, K);
	cout << M << ' '<< N << ' ' << K;//main_dp(left_up, left_down, right_up, right_down, row, column, K);
}
