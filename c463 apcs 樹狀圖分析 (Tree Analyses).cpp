#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
}

// int DFS(vector<vector<int>> tr, int now, int l) {
// 	if (tr[now].empty()) return l;
// 	int m = 0, q = -1;
// 	for (m = 0;m < tr[now].size();m++) {
// 		q = max(q, DFS(tr, tr[now][m], l + 1));
// 	}
// 	return q;
// }

// int main() {
// 	int n, i, j, p, q, root;
// 	scanf("%d", &n);
// 	vector<vector<int>> tree(n);
// 	vector<bool> flg(n, true);
// 	for (i = 0;i < n;i++) {
// 		scanf("%d", &j);
// 		if (j) {
// 			for (p = 0;p < j;p++) {
// 				scanf("%d", &q);
// 				q--;
// 				tree[i].push_back(q);
// 				flg[q] = false;
// 			}
// 		}
// 	}
// 	for (i = 0;i < n;i++) {
// 		if (flg[i]) {
// 			root = i;
// 			break;
// 		}
// 	}
// 	j = 0;
// 	for (i = 0;i < n;i++) {
// 		j += DFS(tree, i, 0);
// 	}
// 	cout << root + 1  << '\n' << j << endl;
// 	// for (i = 0;i < tree.size();i++) {
// 	// 	for (j = 0;j < tree[i].size();j++) {
// 	// 		cout<< tree[i][j] <<' ';
// 	// 	}
// 	// 	cout << endl;
// 	// }
// 	cin >> i;
// }