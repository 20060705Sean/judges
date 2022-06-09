#include <bits/stdc++.h>
using namespace std;

int main() {
	int M, N, Q, i, j, p, q, r, sum = 0, max_sum = 0;
	bool flag;
	scanf("%d%d%d", &M, &N, &Q);
	vector<vector<int>> lines(M + 1, vector<int>(N + 1, 0)), stakes(M + 1, vector<int>(N + 1, 0));
	while(Q--) {
		scanf("%d%d%d", &p, &q, &r);
		if (r) {
			// Remove stake
			stakes[p][q] = 0;
			lines[p][q] = 0;
			// Up
			if (lines[p - 1][q]) {
				for (i = p - 1;i >= 0;i--) {
					if (stakes[i][q]) break;
					lines[i][q]--;
				}
			}
			// Down
			if (lines[p + 1][q]) {
				for (i = p + 1;i < M;i++) {
					if (stakes[i][q]) break;
					lines[i][q]--;
				}
			}
			// Right
			if (lines[p][q + 1]) {
				for (i = q + 1;i < N;i++) {
					if (stakes[p][i]) break;
					lines[p][i]--;
				}
			}
			// Left
			if (lines[p][q - 1]) {
				for (i = q - 1;i >= 0;i--) {
					if (stakes[p][i]) break;
					lines[p][i]--;
				}
			}
		} else {
			// Append stake
			stakes[p][q] = 1;
			lines[p][q] = 1;
			// Up
			flag = false;
			for (i = p - 1;i >= 0;i--) {
				if (stakes[i][q] == 1) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = p - 1;j > i;j--) {
					if (lines[j][q] == 2) continue;
					else if (lines[j][q] == 0) lines[j][q]++;
					else {
						if (M > j && j > 0) {
							if ((lines[j][q + 1] != 0) && (lines[j][q - 1] != 0)) lines[j][q] = 2;
						} else {
							lines[j][q] = 1;
						}
					}
				}
			}
			// Down
			flag = false;
			for (i = p + 1;i < M;i++) {
				if (stakes[i][q] == 1) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = p + 1;j < i;j++) {
					if (lines[j][q] == 2) continue;
					else if (lines[j][q] == 0) lines[j][q]++;
					else {
						if (M > j && j > 0) {
							if ((lines[j][q + 1] != 0) && (lines[j][q - 1] != 0)) lines[j][q] = 2;
						} else {
							lines[j][q] = 1;
						}
					}
				}
			}
			// Right
			flag = false;
			for (i = q + 1;i < N;i++) {
				if (stakes[p][i] == 1) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = q + 1;j < i;j++) {
					if (lines[p][j] == 2) continue;
					else if (lines[p][j] == 0) lines[p][j]++;
					else {
						if (N > j && j > 0) {
							if ((lines[p + 1][j] != 0) && (lines[p - 1][j] != 0)) lines[p][j] = 2;
						} else {
							lines[p][j] = 1;
						}
					}
				}
			}
			// Left
			flag = false;
			for (i = q - 1;i >= 0;i--) {
				if (stakes[p][i] == 1) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = q - 1;j > i;j--) {
					if (lines[p][j] == 2) continue;
					else if (lines[p][j] == 0) lines[p][j]++;
					else {
						if (N > j && j > 0) {
							if ((lines[p + 1][j] != 0) && (lines[p - 1][j] != 0)) lines[p][j] = 2;
						} else {
							lines[p][j] = 1;
						}
					}
				}
			}
			// Calculate line and stakes occupied space
			max_sum = 0;
			for (i = 0;i < M;i++) {
				for (j = 0;j < N;j++) {
					if(lines[i][j]) max_sum++;
				}
			}
		}
		/*
		for (i = 0;i < M;i++) {
			for (j = 0;j < N;j++) {
				cout << lines[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << endl; 
		*/
	}
	// Calculate line and stakes occupied space
	sum = 0;
	for (i = 0;i < M;i++) {
		for (j = 0;j < N;j++) {
			if(lines[i][j]) sum++;
		}
	}
	cout << max_sum << '\n' << sum;
	cin >> i;
	return 0;
}