#include <bits/stdc++.h>
using namespace std;

/*
G
1:3,2
2:1,3
3:1,2,4
4:3

	0001001000110100010101100111
	1	2	3	4	5	6	7	
1	0	1 	0 	1 	0 	1 	1 	
2	1 	0 	0 	1 	1 	1 	1 	
3	1 	1 	1 	0 	0 	0 	0 	
4	0 	0 	0 	1 	1 	1 	1 	
*/

int main() {
	int i, j, k, v, e;
	scanf("%d%d", &v, &e);
	vector<vector<int>>graph(v);
	vector<vector<bool>>dp(v, vector<bool>(1 << v, 0));
	for (i = 0;i < e;i++) {
		scanf("%d%d", &j, &k);
		graph[j].push_back(k);
		graph[k].push_back(j);
		dp[j][(1 << k) - 1] = true;
		dp[k][(1 << j) - 1] = true;
	}
	for (i = 0;i < dp.size();i++) {
		for (j = 0;j < dp[i].size();j++) {
			cout<< dp[i][j] << ' ';
		}
		cout << endl;
	}
	cin >> e; 
}