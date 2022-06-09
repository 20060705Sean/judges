#include<bits/stdc++.h>
using namespace std;

/*
just BFS for each query
*/
vector<int> now, next_, temp;
vector<bool> vis(15*10e4 + 5);

void debug(vector<int> a) {
	cout <<endl<< "*****" << endl;
	for(int i = 0;i < (int)a.size();i++) cout << a[i] << ' ';
	cout <<endl<< "*****" << endl;
}
void debug2d(vector<vector<int>> G) {
	cout <<endl<< "*****" << endl;
	for (int i = 0;i < (int)G.size();i++) {
		for(int j = 0;j < (int)G[i].size();j++) cout << G[i][j] << ' ';
		cout << endl;
	}
	cout << "*****" << endl;
}

bool is_in_vec(vector<int> a, int x) {
	for (int i = 0;i < (int)a.size();i++) {
		if (a[i] == x) return false;
	}
	return true;
}
int BFS(vector<vector<int>> G, int x, int k) {
	now = G[x];
	fill(vis.begin(), vis.end(), 1);
	vis[x] = 0;
	int sum = x, i, j;
	while (k--) {
		//debug(next_);
		next_.resize(0);
		for (i = 0;i < (int)now.size();i++) {
			sum += now[i];
			vis[now[i]] = 0;
			temp = G[now[i]];
			for (j = 0;j < (int)temp.size();j++) {
				if (vis[temp[j]]) {
					if (is_in_vec(next_, temp[j])) next_.push_back(temp[j]);
				}
			}
		}
		now = next_;
	}
	return sum;
}


int main() {
	int N, M, Q, i, p, q;scanf("%d%d", &N, &M);
	vector<vector<int>> G(N + 1);
	for (i = 0;i < M;i++) {
		scanf("%d%d", &p, &q);
		if (is_in_vec(G[p], q)) G[p].push_back(q);
		if (is_in_vec(G[q], p)) G[q].push_back(p);
	}
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d", &p, &q);
		printf("%d\n", BFS(G, p, q));
	}

}
