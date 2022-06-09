#include <bits/stdc++.h>
using namespace std;

template<typename T>
void debug_vec(T a) {
	for(int i = 0;i < (int)a.size();i++) cout << a[i] << ' ';
	cout << endl;
}

int main() {
	int N, n, i, s;scanf("%d", &N);
	vector<int> nums;
	while (N--) {
		scanf("%d", &n);
		nums.resize(n);
		for (i = 0;i < n;i++) scanf("%d", &nums[i]);
		for (i = 1;i < n;i++) {
			if (nums[i - 1] == nums[i])
		}
	}
}