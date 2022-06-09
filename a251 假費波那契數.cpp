#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

void debug_vec(vector<int> A) {
	for (int i = 0;i < (int)A.size();i++) {
		cout << A[i] << ' ';
	}
	cout << endl;
}

int main() {
	int T, n, i;
	scanf("%d", &T);
	while (T--) {
		vector<int> nums(4);
		scanf("%d%d%d%d%d", &n, &nums[0], &nums[1], &nums[2], &nums[3]);
		for (i = 4;i <= n;i++) {
			nums.push_back(nums[i - 1] + nums[i - 4]);
		}
		sort(nums.begin(), nums.end());
		cout << nums[(int)(n / 2)] << endl;
	}
}