#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G = {
	{}, {2, 4}, {1, 3, 5}, {2, 6}, {1, 5, 7},
	{2, 4, 6, 8}, {3, 5, 9}, {4, 8}, {5, 7, 9}, {6, 8}
};

int main() {
	int n, i, j, p;scanf("%d", &n);
	bitset<10> mine;
	for (i = 0;i < n;i++) {
		mine = 0;
		scanf("%d", &p);
		for (j = 0;j < (int)G[p].size();j++) mine[G[p][j]] = 1;
		scanf("%d", &p);
		mine[p] = 0;
		for (j = 0;j < (int)G[p].size();j++) mine[G[p][j]] = 0;
		scanf("%d", &p);
		mine[p] = 0;
		for (j = 0;j < (int)G[p].size();j++) mine[G[p][j]] = 0;
		mine[0] = 1;

		for (j = 1;j < 10;j++) {
			if (mine[j]) {
				printf("%d ", j);
				mine[0] = 0;
			}
		}
		if (mine[0]) printf("Empty");
		printf("\n");
	}
}
