#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

struct dot {
	int x, y;
	void input() {
		scanf("%d%d", &x, &y);
	}
	bool operator< (dot &that) {
		if (this->x == that.x) {
			return this->y < that.y;
		}
		return this->x < that.x;
	}
	void output() {
		printf("%d %d\n", x, y);
	}
};

int main() {
	int n, i;
	scanf("%d", &n);
	vector<dot> dots(n);
	for (i = 0;i < n;i++) dots[i].input();
	sort(dots.begin(), dots.end());
	for (i = 0;i < n;i++) dots[i].output();
}