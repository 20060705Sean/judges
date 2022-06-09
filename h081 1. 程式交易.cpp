#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, n, D, all = 0, now;
	bool get = true;
	scanf("%d%d", &n, &D);
	vector<int> price(n);
	for (i = 0;i < n;i++) scanf("%d", &price[i]);
	now = price[0];
	for (i = 1;i < n;i++) {
		if ((price[i] >= now + D) && get) {
			all += price[i] - now;
			now = price[i];
			get = false;
		} else if (!get && now - D >= price[i]) {
			get = true;
			now = price[i];
		}
	}
	cout << all;
	return 0;
}