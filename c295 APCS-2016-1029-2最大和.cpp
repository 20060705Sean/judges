#include <bits/stdc++.h>
using namespace std;

int find_max(vector<int> m) {
	int max = 0;
	for_each(m.begin(), m.end(), [&max](int k){if (k > max) max = k;});
	return max;
}

int main() {
	// vars and inputs
	int N, M, summary = 0, i, j;
	cin >> N >> M;
	vector<int> chosen_numbers, numbers_can_devide;
	vector<vector<int>> numbers(N, vector<int>(M, 0));
	for (i = 0; i < N;i++) {
		for (j = 0;j < M;j++) {
			cin >> numbers[i][j];
		}
	}
	// Calculations
	for_each(numbers.begin(), numbers.end(), [&summary, &chosen_numbers, &i](vector<int> smaller_vector){
		i = find_max(smaller_vector);
		summary += i;
		chosen_numbers.push_back(i);
	});
	// outputs
	cout << summary << endl;
	for_each(chosen_numbers.begin(), chosen_numbers.end(), [&summary, &numbers_can_devide](int m) {
		if (summary % m == 0) numbers_can_devide.push_back(m);
	});
	if (numbers_can_devide.size() == 0) cout << -1;
	else {
		for_each(numbers_can_devide.begin(), numbers_can_devide.end() - 1, [](int m){cout << m <<' ';});
		cout << *(numbers_can_devide.end() - 1);
	}
	cin >> N;
	return 0;
}