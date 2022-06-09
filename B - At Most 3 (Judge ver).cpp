#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, j, k, N, W, sum = 0;
	scanf("%d%d", &N, &W);
	int A[N];
	vector<bool> yes(3 * 10e6 + 1, 0);
	for (i = 0;i < N;i++) scanf("%d", &A[i]);
	if (N >= 3) {
		for (i = 0;i < N;i++) {for (j = 0;j < i;j++) {for (k = 0;k < j;k++) {
			yes[A[i] + A[j] + A[k]] = 1;
		}}}
	}
	if (N >= 2) {
		for (i = 0;i < N;i++) {for (j = 0;j < i;j++) {
			yes[A[i] + A[j]] = 1;
		}}
	}
	for (i = 0;i < N;i++) {
		yes[A[i]] = 1;
	}
	for (i = 0;i <= W;i++) {
		sum += yes[i];
	}
	cout << sum;
}