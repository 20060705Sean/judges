#pragma gcc optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int main() {
	// 由小到大排序對半對折檢查
	int W, n, upper, lower, i, sum;scanf("%d%d", &W, &n);
	vector<int> items(n);sum = n;
	for (i = 0;i < n;i++) scanf("%d", &items[i]);
	sort(items.begin(), items.end());
	for (lower = 0, upper = n - 1;upper > lower;) {
		if (items[lower] + items[upper] > W) upper--;
		else upper--,lower++,sum--;
	}
	printf("%d", sum);
}
