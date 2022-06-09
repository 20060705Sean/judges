#include<bits/stdc++.h>
using namespace std;

/*
計算前綴和的前綴和就可以快速得到答案
假設我們有
A = {0 a1 a2 a3 a4 a5}
pA = {
	0
	a1
	a1+a2
	a1+a2+a3
	a1+a2+a3+a4
	a1+a2+a3+a4+a5
}
ppA = {
	0
	a1
	2a1+a2
	3a1+2a2+a3
	4a1+3a2+2a3+a4
	5a1+4a2+3a3+2a4+a5
}
欲求S = ppA[R] - ppA[L-1] - (R-L+1) * pA[L-1]
*/

void debug(vector<long long> a) {
	cout << endl;
	for (int i = 0;i < (int)a.size();i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

vector<long long> calculate_prefix(vector<long long> x) {
	vector<long long> result(x.size(), 0);
	for (int i = 1;i < (int)x.size();i++) {
		result[i] = result[i - 1] + x[i];
	}
	return result;
}

int main() {
	int n, q, x, y, i;long long sum;scanf("%d", &n);
	vector<long long> a(n + 1, 0), prefix_a, prefix_prefix_a;
	for (i = 1;i <= n;i++) scanf("%lld", &a[i]);
	prefix_a = calculate_prefix(a);prefix_prefix_a = calculate_prefix(prefix_a);
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &x, &y);
		printf("%lld\n", prefix_prefix_a[y] - prefix_prefix_a[x - 1] - (y - x + 1) * prefix_a[x - 1]);
	}
}
