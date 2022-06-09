#include <bits/stdc++.h>
using namespace std;

int main() {
	int M, N, Q, i, j, p, q, r, sum = 0, max_sum = 0;
	bool flag;
	scanf("%d%d%d", &M, &N, &Q);
	vector<vector<bool>> lines(M + 1, vector<bool>(N + 1, false)), stakes(M + 1, vector<bool>(N + 1, false));
	while(Q--) {
		scanf("%d%d%d", &p, &q, &r);
		if (r) {
			// Remove stake
			stakes[p][q] = false;
			lines[p][q] = false;
			// Up
			if (lines[p - 1][q]) {
				for (i = p - 1;i >= 0;i--) {
					if (stakes[i][q]) break;
					lines[i][q] = false;
				}
			}
			// Down
			if (lines[p + 1][q]) {
				for (i = p + 1;i < M;i++) {
					if (stakes[i][q]) break;
					lines[i][q] = false;
				}
			}
			// Right
			if (lines[p][q + 1]) {
				for (i = q + 1;i < N;i++) {
					if (stakes[p][i]) break;
					lines[p][i] = false;
				}
			}
			// Left
			if (lines[p][q - 1]) {
				for (i = q - 1;i >= 0;i--) {
					if (stakes[p][i]) break;
					lines[p][i] = false;
				}
			}
		} else {
			// Append stake
			stakes[p][q] = true;
			lines[p][q] = true;
			// Up
			flag = false;
			for (i = p - 1;i >= 0;i--) {
				if (stakes[i][q] == true) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = p - 1;j > i;j--) {
					lines[j][q] = true;
				}
			}
			// Down
			flag = false;
			for (i = p + 1;i < M;i++) {
				if (stakes[i][q] == true) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = p + 1;j < i;j++) {
					lines[j][q] = true;
				}
			}
			// Right
			flag = false;
			for (i = q + 1;i < N;i++) {
				if (stakes[p][i] == true) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = q + 1;j < i;j++) {
					lines[p][j] = true;
				}
			}
			// Left
			flag = false;
			for (i = q - 1;i >= 0;i--) {
				if (stakes[p][i] == true) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = q - 1;j > i;j--) {
					lines[p][j] = true;
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
		////
		for (i = 0;i < M;i++) {
			for (j = 0;j < N;j++) {
				cout << lines[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << endl; 
		////
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