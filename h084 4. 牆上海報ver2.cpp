#include <bits/stdc++.h>
using namespace std;
int main() {
	// global vars
	int fences_amount, poster_amount;
	int max_height;
	vector<int> fences_height, poster_widths;
	// inputs
	int i, k;
	cin >> fences_amount >> poster_amount;
	for (i = 0;i < fences_amount;i++) {
		cin >> k;
		if (k > max_height) max_height = k;
		fences_height.push_back(k);
	}
	for (i = 0;i < poster_amount;i++) {
		cin >> k;
		poster_widths.push_back(k);
	}
	// Calculation
	// Binary Search
	int L = 1, R = max_height, M, temp_left, poster_counter;
	while (L != R) {
		M = (L + R + 1) / 2;
		temp_left = -1;
		poster_counter = 0;
		// try cram posters on height M
		for (i = 0;i < fences_amount;i++) {
			if (fences_height[i] < M) temp_left = i;
			else if ( i - temp_left == poster_widths[poster_counter]) {
				temp_left = i;
				poster_counter++;
				if (poster_counter == poster_amount) break;
			}
		}
		if (poster_counter == poster_amount) L = M;
		else R = M - 1;
	}
	// Output
	cout << L;
	cin >> L;
	return 0;
}