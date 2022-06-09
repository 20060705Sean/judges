#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j, k, s = 0, maxima = -10;scanf("%d", &n);
	vector<int> a;
	set<int> A;
	set<int>::iterator m;
	for (i = 0;i < n;i++) {
		scanf("%d", &j);
		a.push_back(j);
		A.insert(j);
		if (j > maxima) maxima = j;
	}
	m = A.end();
	for (i = 0;i < n - 1;i++) {
		for (j = 0;j < i;j++) {
			k = a[i] + a[i + 1];
			if (k <= maxima) {
				if (A.find(k) != m) s++;
			}
		}
	}
	cout << s;
	cin >> s;
}
