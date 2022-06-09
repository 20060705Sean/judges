#include<bits/stdc++.h>
using namespace std;

void update(vector<int> &a, int idx) {
	while (idx <= a.size() - 1) {
		a[idx]++;
		idx += idx & (-idx);
	}
}

int query(vector<int> &a, int idx) {
	int sum = 0;
	while (idx) {
		sum += a[idx];
		//cout << idx << ' ';
		idx -= idx & (-idx);
	}
	//cout << endl;
	return sum;
}

int main() {
	int n, i, j;scanf("%d", &n);
	vector<vector<int>> range(n + 1);
	vector<int> BIT(2 * n + 1, 0);
	for (i = 1;i <= 2 * n;i++) {
		scanf("%d", &j);
		range[j].push_back(i);
	}
	long long result = 0;
	for (i = 1;i <= n;i++) {
		//for (j = 0;j < n + 1;j++) cout << BIT[j] << ' ';
		//cout << endl;
		result += abs(query(BIT, range[i][0]) - query(BIT, range[i][1]));
		//cout << query(BIT, range[i][0]) << ' ' << query(BIT, range[i][1]) << ' ' << range[i][1];
		update(BIT, range[i][0]);
		update(BIT, range[i][1]);
		//cout << result << ' ';
	}
	cout << result;
}
