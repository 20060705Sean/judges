#include <bits/stdc++.h>
using namespace std;

bool process(vector<int> A, int maxima) {
	sort(A.rbegin(), A.rend());
	long long pivot = 2 * A[0] + 1;
	for (int i = 1;i < A.size() - 1;i++) {
		pivot += A[i]; pivot++;
		if (pivot >	maxima) return 0;
	}
	pivot++;
	if (pivot > maxima) return 0;
	return 1;
}

int main() {
	long long m = 1966719943;
	m = m + 799843967;
	cout << m;
	int n;scanf("%d", &n);
	int p, q, i;
	while (n--) {
		scanf("%d%d", &p, &q);
		vector<int> num(p);
		for (i = 0;i < p;i++) scanf("%d", &num[i]);
		if (process(num, q)) printf("YES\n");
		else printf("NO\n");
	}
	cin >> i;
}