#include <bits/stdc++.h>
using namespace std;

int main() {
	// vars and init inputs
	int number_of_dices, number_of_inputs, a, b, i;
	cin >> number_of_dices >> number_of_inputs;
	vector<vector<int>> dices(number_of_dices, vector<int> {5, 1, 2, 6, 3, 4});
	// Calculation
	for (i = 0;i < number_of_inputs;i++) {
		cin >> a >> b;
		a--;
		if (b > 0) swap(dices[a], dices[--b]);
		else if (b == -1) {
			swap(dices[a][1], dices[a][4]);
			swap(dices[a][4], dices[a][3]);
			swap(dices[a][3], dices[a][5]);
		} else {
			swap(dices[a][3], dices[a][2]);
			swap(dices[a][2], dices[a][1]);
			swap(dices[a][1], dices[a][0]);
		}
	}
	// outputs
	for_each(dices.begin(), dices.end(), [](vector<int> m){cout << m[1] << ' ';});
	return 0;
}