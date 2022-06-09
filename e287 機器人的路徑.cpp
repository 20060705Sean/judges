#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, i, j, k, x, y, z = -1;
	scanf("%d%d", &n, &m);
	vector<vector<int>> mapping(n, vector<int>(m));
	vector<vector<bool>> note(n, vector<bool>(m, false));
	for (i = 0;i < n;i++) {for (j = 0;j < m;j++) {
		scanf("%d", &k);
		mapping[i][j] = k;
		if (k > z) 
	}}

}



// int main() {
// 	int n, m, i, j, min_val = 1000001, min_i, min_j;
// 	long long sum = 0;
// 	bool flag = false;
// 	cin >> n >> m;
// 	vector<vector<int>> block_array(n, vector<int>(m, 0));
// 	vector<vector<bool>> did_i_walked_here(n, vector<bool>(m, 0));
// 	for (i = 0;i < n;i++) {
// 		for (j = 0;j < m;j++) {
// 			cin >> block_array[i][j];
// 			if (block_array[i][j] < min_val) {
// 				min_i = i;
// 				min_j = j;
// 				min_val = block_array[i][j];
// 			}
// 		}
// 	}

// 	i = min_i;
// 	j = min_j;
// 	while (true) {
// 		flag = false;
// 		did_i_walked_here[i][j] = 1;
// 		sum += block_array[i][j];
// 		min_val = 1000001;
// 		if (i - 1 > 0) {
// 			if (block_array[i - 1][j] < min_val && !did_i_walked_here[i - 1][j]) {
// 				min_i = i - 1;
// 				min_j = j;
// 				min_val = block_array[i - 1][j];
// 				flag = true;
// 			}
// 		}
// 		if (i + 1 < n) {
// 			if (block_array[i + 1][j] < min_val && !did_i_walked_here[i + 1][j]) {
// 				min_i = i + 1;
// 				min_j = j;
// 				min_val = block_array[i + 1][j];
// 				flag = true;
// 			}
// 		}
// 		if (j - 1 > 0) {
// 			if (block_array[i][j - 1] < min_val && !did_i_walked_here[i][j - 1]) {
// 				min_i = i;
// 				min_j = j - 1;
// 				min_val = block_array[i][j - 1];
// 				flag = true;
// 			}
// 		}
// 		if (j + 1 < m) {
// 			if (block_array[i][j + 1] < min_val && !did_i_walked_here[i][j + 1]) {
// 				min_i = i;
// 				min_j = j + 1;
// 				min_val = block_array[i][j + 1];
// 				flag = true;
// 			}
// 		}
// 		if (!flag) break;
// 		i = min_i;
// 		j = min_j;
// 	}

// 	cout << sum;

// 	return 0;
// }