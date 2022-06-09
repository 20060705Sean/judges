#include <bits/stdc++.h>
using namespace std;

int main() {
	int M, N, Q, i, j, p, q, r, sum = 0, max_sum = 0;
	bool flag;
	scanf("%d%d%d", &M, &N, &Q);
	vector<vector<pair<bool, bool>>> lines(M + 2, vector<pair<bool, bool>>(N + 2, {false, false}));
	vector<vector<bool>> stakes(M + 1, vector<bool>(N + 1, false));
	
	while(Q--) {
		scanf("%d%d%d", &p, &q, &r);
		p++;
		q++;
		if (r) {
			// Remove stake
			stakes[p][q] = false;
			lines[p][q] = {false, false};
			// Up
			if (lines[p - 1][q].first) {
				for (i = p - 1;i > 0;i--) {
					if (stakes[i][q]) break;
					lines[i][q].first = false;
				}
			}
			// Down
			if (lines[p + 1][q].first) {
				for (i = p + 1;i < M + 1;i++) {
					if (stakes[i][q]) break;
					lines[i][q].first = false;
				}
			}
			// Right
			if (lines[p][q + 1].second) {
				for (i = q + 1;i < N + 1;i++) {
					if (stakes[p][i]) break;
					lines[p][i].second = false;
				}
			}
			// Left
			if (lines[p][q - 1].second) {
				for (i = q - 1;i > 0;i--) {
					if (stakes[p][i]) break;
					lines[p][i].second = false;
				}
			}
		} else {
			// Append stake
			stakes[p][q] = true;
			lines[p][q] = {true, true};
			// Up
			flag = false;
			for (i = p - 1;i > 0;i--) {
				if (stakes[i][q] == true) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = p - 1;j > i;j--) {
					lines[j][q].first = true;
				}
			}
			// Down
			flag = false;
			for (i = p + 1;i < M + 1;i++) {
				if (stakes[i][q] == true) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = p + 1;j < i;j++) {
					lines[j][q].first = true;
				}
			}
			// Right
			flag = false;
			for (i = q + 1;i < N + 1;i++) {
				if (stakes[p][i] == true) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = q + 1;j < i;j++) {
					lines[p][j].second = true;
				}
			}
			// Left
			flag = false;
			for (i = q - 1;i > 0;i--) {
				if (stakes[p][i] == true) {
					flag = true;
					break;
				}
			}
			if (flag) {
				for (j = q - 1;j > i;j--) {
					lines[p][j].second = true;
				}
			}
			// Calculate line and stakes occupied space
			max_sum = 0;
			for (i = 1;i < M + 1;i++) {
				for (j = 1;j < N + 1;j++) {
					if(lines[i][j].first || lines[i][j].second) max_sum++;
				}
			}
		}
		
		// for (i = 1;i < M + 1;i++) {
		// 	for (j = 1;j < N + 1;j++) {
		// 		cout << lines[i][j].first << lines[i][j].second << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// cout << endl; 
		
	}
	// Calculate line and stakes occupied space
	sum = 0;
	for (i = 1;i < M + 1;i++) {
		for (j = 1;j < N + 1;j++) {
			if(lines[i][j].first || lines[i][j].second) sum++;
		}
	}
	cout << max_sum << '\n' << sum;
	cin >> i;
	return 0;
}