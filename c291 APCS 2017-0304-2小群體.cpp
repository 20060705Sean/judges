#include <bits/stdc++.h>
using namespace std;

int main() {
	// vars and inputs
	int N, total = 0, next_friend, i, j;
	cin >> N;
	vector<bool> already_walked_notation(N);
	vector<int> my_friend(N);
	for (i = 0;i < N;i++) {
		cin >> j;
		my_friend[i] = j;
	}
	// calculation
	for (i = 0;i < N;i++) {
		if (already_walked_notation[i]) continue;
		next_friend = my_friend[i];
		while (next_friend != i) {
			already_walked_notation[next_friend] = true;
			next_friend = my_friend[next_friend];
		}
		total++;
	}
	// outputs
	cout << total;
	return 0;
}