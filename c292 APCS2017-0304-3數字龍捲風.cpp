#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, direction, i, j, adder = 1, temp_adder_small = 0, temp_adder_big = 0;
	cin >> N;
	cin >> direction;
	vector<vector<int>> G(N, vector<int>(N, 0));
	for (i = 0;i < N;i++) {
		for (j = 0;j < N;j++) cin >> G[i][j];
	}
	i = N / 2;j = N / 2;
	while (adder <= N) {
		cout << G[i][j];
		// cout << i << ' ' << j  << ' ' << direction<< endl;
		switch (direction) {
			case 0:
				j--;
				break;
			case 1:
				i--;
				break;
			case 2:
				j++;
				break;
			case 3:
				i++;
				break;
		}
		if (i == -1 or j == -1 or i >= N or j >= N) break;
		temp_adder_small++;
		if (temp_adder_small == adder) {
			temp_adder_big++;
			temp_adder_small = 0;
			if (temp_adder_big == 2) {
				temp_adder_big = 0;
				adder++;
			}
			direction = (direction + 1) % 4;
		}
	}
	cin >> N;
	return 0;
}
