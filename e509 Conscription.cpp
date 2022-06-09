#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

struct edge {
	int girl, boy, connection;
	void input() {
		scanf("%d%d%d", &girl, &boy, &connection);
	}
	bool operator< (edge &that) {
		return this->connection > that.connection;
	}
};

vector<int> djs;
int find_head(int a) {
	if (djs[a] == -1) return a;
	return djs[a] = find_head(djs[a]);
}

void debug_edge(vector<edge> A) {
	for (int i = 0;i < (int)A.size();i++) {
		cout << '[' << A[i].girl << ',' << A[i].boy << ',' << A[i].connection << ']' << ' ';
	}
	cout << endl;
}

int main() {
	int T, i, girl, boy, sum, find_boy, find_girl, relations;
	scanf("%d", &T);
	vector<edge> net;
	edge now;
	while (T--) {
		scanf("%d%d%d", &girl, &boy, &relations);
		net.resize(relations);
		djs.resize(girl + boy);
		for (i = 0;i < (int)djs.size();i++) djs[i] = -1;
		for (i = 0;i < relations;i++) net[i].input();
		sort(net.begin(), net.end());
		sum = 0;
		for (i = 0;i < (int)net.size();i++) {
			now = net[i];
			find_boy = find_head(now.boy + girl);
			find_girl = find_head(now.girl);
			if (find_boy != find_girl) {
				sum += now.connection;
				djs[find_boy] = find_girl;
			}
		}
		cout << 10000 * (boy + girl) - sum << '\n';
	}
}
