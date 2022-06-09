#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, i, j;
	scanf("%d", &N);
	vector<pair<int, int>> numbers(N, {0, 0});
	vector<int> prev(N + 1), not_sorted(N + 1);
	for (i = 1;i <= N;i++) {
		scanf("%d", &j);
		numbers[i - 1] = {j, i};
		prev[i] = prev[i - 1] + j;
		not_sorted[i] = j;
	}
	sort(numbers.begin(), numbers.end());
	//Computation
	int L = 1, R = N, idx = 0, left_sum, right_sum;
	while (L < R) {
		while (numbers[idx].second > R || numbers[idx].second < L) idx++;
		i = numbers[idx].second;
		left_sum = prev[i - 1] - prev[L - 1];
		right_sum = prev[R] - prev[i];
		if (right_sum >= left_sum) L = i + 1;
		else R = i - 1;
	}
	printf("%d\n", not_sorted[L]);
	return 0;
}