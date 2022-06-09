#include <bits/stdc++.h>
using namespace std;

void update(vector<int>&BIT, int x, int d) {
	int N = BIT.size() - 1;
	x++;
	while (x <= N) {
		BIT[x] += d;
		x += x & (-x);
	}
}

long long query(vector<int>BIT, int x) {
	long long result = 0;
	x++;
	while (x) {
		result += BIT[x];
		x -= x & (-x);
	}
	return result;
}

void debug_vec(vector<int> a) {
	for (int i = 0;i < (int)a.size();i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	int i, j, k, N, Q;scanf("%d%d", &N, &Q);
	vector<int> BIT(N + 1, 0), arr(N);
	for (i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
		update(BIT, i, arr[i]);
	}
	for (i = 0;i < Q;i++) {
		scanf("%d%d", &j);
		if (j == 1) {
			scanf("%d%d", &j, &k);
			update(BIT, j, k)
		} else { 
			scanf("%d", &j);
		}
	}
	cin >> i;
}