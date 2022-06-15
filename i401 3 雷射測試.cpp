#include<bits/stdc++.h>
using namespace std;

/*
define the directions of light:
0 right
1 left
2 up
3 down

reflections:
／:
0 > 2
1 > 3
2 > 0
3 > 1
f(x) = (x + 2) % 4
＼:
0 > 3
1 > 2
2 > 1
3 > 0
g(x) = 3 - x

psuedo::start

mirrors sort by x -> X
mirrors sort by y -> Y
x_of_light = 0
y_of_light = 0
dir = 0
if (dir = 0) {
	new_mirror = upper_bound(Y[y_of_light], x_of_light)
}
if (dir = 1) {
	new_mirror = lower_bound(Y[y_of_light], x_of_light) - 1
}
if (dir = 2) {
	new_mirror = upper_bound(X[x_of_light], y_of_light)
}
if (dir = 3) {
	new_mirror = lower_bound(X[x_of_light], y_of_light) - 1
}
new_x = mirror.x
new_y = mirror.y
new_dir = f(dir) if new_mirror.dir = 0 else g(dir)
*/

struct data{
	int num;
	bool dir;
	bool operator<(const data other) const {
		return num < other.num;
	}
};

void debug(vector<vector<data>> a) {
	for (int i = 0;i < a.size();i++) {
		if (a[i].empty()) continue;
		cout << i << ": ";
		for (int j = 0;j < a[i].size();j++) {
			cout << a[i][j].num << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int n, i, x, y, dir;
	data new_mirror, temp;
	vector<data>::iterator now;
	vector<vector<data>> X(30005), Y(60010);
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%d%d%d", &x, &y, &dir);
		y += 30000;
		X[x].push_back({y, dir});
		Y[y].push_back({x, dir});
	}
	for (i = 1;i < 30001;i++) sort(X[i].begin(), X[i].end());
	for (i = 0;i < 60001;i++) sort(Y[i].begin(), Y[i].end());
	x = 0;
	y = 30000;
	dir = 0;
	int sum = 0;
	while (1) {
		if (dir == 0) {
			if (Y[y].empty()) break;
			temp = {x, 0};
			now = upper_bound(Y[y].begin(), Y[y].end(), temp);
			if (now == Y[y].end()) break;
			new_mirror = *now;
			x = new_mirror.num;
			dir = (new_mirror.dir)?3:2;
		} else if (dir == 1) {
			if (Y[y].empty()) break;
			temp = {x, 0};
			now = lower_bound(Y[y].begin(), Y[y].end(), temp);
			if (now == Y[y].begin()) break;
			new_mirror = *(--now);
			x = new_mirror.num;
			dir = (new_mirror.dir)?2:3;
		} else if (dir == 2) {
			if (X[x].empty()) break;
			temp = {y, 0};
			now = upper_bound(X[x].begin(), X[x].end(), temp);
			if (now == X[x].end()) break;
			new_mirror = *now;
			y = new_mirror.num;
			dir = (new_mirror.dir)?1:0;
		} else {
			if (X[x].empty()) break;
			temp = {y, 0};
			now = lower_bound(X[x].begin(), X[x].end(), temp);
			if (now == X[x].begin()) break;
			new_mirror = *(--now);
			y = new_mirror.num;
			dir = (new_mirror.dir)?0:1;
		}
		sum++;
	}
	cout << sum;
}
