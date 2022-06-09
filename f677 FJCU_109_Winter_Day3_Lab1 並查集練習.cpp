#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> boss;
int total = 0;
int find_head(int p) {
	if(boss[p].first == p) return p;
	else {
		boss[p].first = find_head(boss[p].first);
		return boss[p].first;
	}
}
void union_set(int p, int q) {
	p = find_head(p);
	q = find_head(q);
	boss[q].first = q;
	if (p == 0 || q == 0) boss[p].second += boss[q].second; 
}
int main() {
	int i, j, k, N, M;
	scanf("%d%d", &N, &M);
	boss.reserve(N);
	for (i = 0;i < N;i++) boss[i] = {i, 1};
	for (i = 0;i < M;i++) {
		scanf("%d%d", &j, &k);
		union_set(j, k);
	}
	for (i = 0;i < N;i++) cout << boss[i].first << ' ' << boss[i].second << endl; 
	cout << boss[0].second;
	cin >> N;
}