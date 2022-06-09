#include <bits/stdc++.h>
using namespace std;

struct edge{
	int u, v, d, idx;
};

int find_head(vector<int> &djs, int p) {
	if (djs[p] == p) return p;
	return djs[p] = find_head(djs, djs[p]);
}
void combine(vector<int> &djs, int m, int n) {
	m = find_head(djs, m);
	n = find_head(djs, n);
	djs[m] = n;
}

int main() {
	int n, m, i;
	scanf("%d%d", &n, &m);
	vector<edge> E(m);
	vector<int> djs(n + 1);
	for (i = 0;i < n + 1;i++) {
		djs[i] = i;
	}
	for (i = 0;i < m;i++) {
		scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].d);
		E[i].idx = i + 1;
	}
	sort(E.begin(), E.end(), [](edge a, edge b){return a.d < b.d;});
	for (i = 0;i < m;i++) {
		if (n == 1)break;
		if (find_head(djs, E[i].u) == find_head(djs, E[i].v)) continue;
		n--;
		printf("%d ", E[i].idx);
		combine(djs, E[i].u, E[i].v);
	}
}
