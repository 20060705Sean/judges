#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

void debug_vec(vector<int> a) {
	for (int i = 0;i < (int)a.size();i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}
int main() {
	int n, m, i, j, l, r, w;
	long long sum = 0;
	scanf("%d%d", &n, &m);
	vector<int> total_work(n, 0), t(n);
	for (i = 0;i < m;i++) {
		scanf("%d%d%d", &l, &r, &w);
		for (j = l - 1;j < r;j++) total_work[j] += w;
	}
	for (i = 0;i < n;i++) scanf("%d", &t[i]);
	sort(total_work.begin(), total_work.end());
	sort(t.rbegin(), t.rend());
	for (i = 0;i < n;i++) sum += total_work[i] * t[i];
	printf("%d", sum);
}
/*
using a greed solution:

input()
total_works
for every work:
	for i in l~r:
		total_works[i] += w

sort by weight
from gib to small add up

*/