// NA 40% because of 2 dfs is too slow
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

vector<int> dis;
void dfs(vector<vector<int>>graph, int root, int prev) {
	for (int i = 0;i < (int)graph[root].size();i++) {
		if (prev != graph[root][i]) {
			dis[graph[root][i]] = dis[root] + 1;
			dfs(graph, graph[root][i], root);
		}
	}
}
void debug_vec(vector<int> a) {
	for (int i = 0;i < (int)a.size();i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}
int main() {
	int n, p, q, i, root;
	while (cin >> n) {
		vector<vector<int>> graph(n);
		dis.resize(n, 1);
		for (i = 0;i < n - 1;i++) {
			scanf("%d%d", &p, &q);
			graph[p].push_back(q);
			graph[q].push_back(p);
			dis[q] = 0;
		}
		for (i = 0;i < n;i++) {
			if (dis[i]) {
				root = i;
				dis[i] = 0;
				break;
			}
		}
		dfs(graph, root, -1);
		p = -1;
		for (i = 0;i < n;i++) {
			if (dis[i] > p) {
				p = dis[i];
				root = i;
			}
		}
		dis[root] = 0;
		dfs(graph, root, -1);
		p = -1;
		for (i = 0;i < n;i++) {
			if (dis[i] > p) {
				p = dis[i];
			}
		}
		cout << p << '\n';
	}
}