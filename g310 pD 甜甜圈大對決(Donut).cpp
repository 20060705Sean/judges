#include <bits/stdc++.h>
using namespace std;

/*
策略：y最大的由x最大的往下找到第一個可以比贏的，接下來y次大的從
剛剛那個位置繼續往下找... O(N)
*/

int main() {
	int N, i, idx, sum = 0;scanf("%d", &N);
	vector<int> x(N), y(N);
	for (i = 0;i < N;i++) scanf("%d", &x[i]);
	for (i = 0;i < N;i++) scanf("%d", &y[i]);
	idx = N - 1;
	for (i = N - 1;i >= 0;i--) {
		if (y[idx] > x[i]) {
			sum++;
			idx--;
		}
	}
	printf("%d", sum);
}
