#include <bits/stdc++.h>
using namespace std;
template<typename T>
void debug_2dvec(T a) {
	for (int i = 0;i < (int)a.size();i++) {
		for (int j = 0;j < (int)a[i].size();j++) {
			cout << a[i][j][0] << a[i][j][1] << a[i][j][2] << ' ';
		}
		cout << endl;
	}}
void add_stick(vector<vector<bitset<3>>> &A, int x, int y) {
	A[x][y] = 1;
	int i, t;
	// up
	t = x;
	for (i = x - 1;i >= 0;i--) {
		if (A[i][y][0]) {
			t = i;
			break;
		}
	}
	for (i = x - 1;i > t;i--) {
		A[i][y][1] = 1;
	}
	// down
	t = x;
	for (i = x + 1;i < (int)A.size();i++) {
		if (A[i][y][0]) {
			t = i;
			break;
		}
	}
	for (i = x + 1;i < t;i++) {
		A[i][y][1] = 1;
	}
	// left
	t = y;
	for (i = y - 1;i >= 0;i--) {
		if (A[x][i][0]) {
			t = i;
			break;
		}
	}
	for (i = y - 1;i > t;i--) {
		A[x][i][2] = 1;
	}
	// right
	t = y;
	for (i = y + 1;i < (int)A[0].size();i++) {
		if (A[x][i][0]) {
			t = i;
			break;
		}
	}
	for (i = y + 1;i < t;i++) {
		A[x][i][2] = 1;
	}}
void remove_stick(vector<vector<bitset<3>>> &A, int x, int y) {
	A[x][y] = 0;
	int i, t;
	// up
	t = x;
	for (i = x - 1;i >= 0;i--) {
		if (A[i][y][0]) {
			t = i;
			break;
		}
	}
	for (i = x - 1;i > t;i--) {
		A[i][y][1] = 0;
	}
	// down
	t = x;
	for (i = x + 1;i < (int)A.size();i++) {
		if (A[i][y][0]) {
			t = i;
			break;
		}
	}
	for (i = x + 1;i < t;i++) {
		A[i][y][1] = 0;
	}
	// left
	t = y;
	for (i = y - 1;i >= 0;i--) {
		if (A[x][i][0]) {
			t = i;
			break;
		}
	}
	for (i = y - 1;i > t;i--) {
		A[x][i][2] = 0;
	}
	// right
	t = y;
	for (i = y + 1;i < (int)A[0].size();i++) {
		if (A[x][i][0]) {
			t = i;
			break;
		}
	}
	for (i = y + 1;i < t;i++) {
		A[x][i][2] = 0;
	}}
int count_blocks(vector<vector<bitset<3>>> &A) {
	int i, j, s = 0;
	for (i = 0;i < (int)A.size();i++) {
		for (j = 0;j < (int)A[0].size();j++) {
			s += A[i][j].any();
		}
	}
	return s;
}
int main() {
	/*
	the bits represent following meanings:
		first: here has a stick
		second: here has a up-down rope
		third: here has a right-left rope
	*/
	int p, q, r, m, n, h, s, ms = 0; scanf("%d%d%d", &m, &n, &h);
	vector<vector<bitset<3>>> course(m, vector<bitset<3>>(n));
	while (h--) {
		scanf("%d%d%d", &p, &q, &r);
		if (r) remove_stick(course, p, q);
		else add_stick(course, p, q);
		s = count_blocks(course);
		if (ms < s) ms = s;
	}
	printf("%d\n%d", ms, s);
	cin >> m;
	return 0;
}