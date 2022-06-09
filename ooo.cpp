#include <bits/stdc++.h>
using namespace std;

struct dot{
	int x, y;
	bool operator<(const dot other) const {
		if (other.x == x) return other.y > y;
		return other.x < x;
	}
};

int main() {
	int i, n;
	dot d, prev;
	scanf("%d", &n);
	vector<dot> a(n);
	for (i = 0;i < n;i++) scanf("%d%d", &a[i].x, &a[i].y);
	priority_queue<dot, vector<dot>> A(a.begin(), a.end());
	prev = A.top();A.pop();
	printf("%d 0\n%d %d\n", prev.x, prev.x, prev.y);
	for (i = 1;i < n;i++) {
		d = A.top();A.pop();
		if (d.x != prev.x) {
			printf("%d %d\n%d %d\n", d.x, prev.y, d.x, d.y);
			prev = d;
		}
	}
	cin >> i;
}