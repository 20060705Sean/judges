#include <bits/stdc++.h>
using namespace std;
// global vars

bool is_this_radius_enough_greed(int diameter, int amount_of_wifiless, int cell_site_max_amount, vector<long> desire_positions) {
	int i, now_cell_site_amount = 1, temp_start_point = desire_positions[0];
	for (i = 0;i < amount_of_wifiless;i++) {
		if (desire_positions[i] - temp_start_point > diameter) {
			now_cell_site_amount++;
			if (now_cell_site_amount > cell_site_max_amount) return false;
			temp_start_point = desire_positions[i];
		}
	}
	return true;
}

int main() {
	// vars and inputs
	int i, k;
	int amount_of_wifiless, cell_site_max_amount;
	vector<long> desire_positions;
	cin >> amount_of_wifiless >> cell_site_max_amount;
	if (amount_of_wifiless == 1) {
		cout << 1;
		return 0;
	}
	for (i = 0;i < amount_of_wifiless;i++) {
		cin >> k;
		desire_positions.push_back(k);
	}
	sort(desire_positions.begin(), desire_positions.end());
	// calculation
	int left = 1, right = desire_positions[amount_of_wifiless - 1] * 2;
	int pivot = (left + right) / 2;
	while (right <= left) {
			pivot = (left + right) / 2;
		if (is_this_radius_enough_greed(pivot, amount_of_wifiless, cell_site_max_amount, desire_positions)) {
			right = pivot;
		} else {
			left = pivot + 1;
		}
	}
	for (pivot = left;i <= right;pivot++) {
		if (is_this_radius_enough_greed(pivot, amount_of_wifiless, cell_site_max_amount, desire_positions)) break;
	}
	cout << pivot;
	return 0;
}