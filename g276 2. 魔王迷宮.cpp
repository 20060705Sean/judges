#include <bits/stdc++.h>
using namespace std;

typedef struct {
	pair<int, int> position;
	pair<int, int> moving_way;
	bool is_alive = true;
} boss;

int main() {
	// vars and inputs
	int boss_amount, width, height, i, j, k;
	cin >> width >> height >> boss_amount;
	vector<boss> boss_data(boss_amount);
	vector<vector<pair<bool, bool>>> bomb_map(width, vector<pair<bool, bool>> (height, {false, false}));
	// first one for bomb, second one for explosion checking
	for (i = 0;i < boss_amount;i++) {
		cin >> j >> k;
		boss_data[i].position = {j, k};
		cin >> j >> k;
		boss_data[i].moving_way = {j, k};
	}
	// computation
	while (boss_amount != 0) {
		for (i = 0;i < boss_data.size();i++) {
			if (boss_data[i].is_alive) {
				bomb_map[boss_data[i].position.first][boss_data[i].position.second].first = true;
				boss_data[i].position.first += boss_data[i].moving_way.first;
				boss_data[i].position.second += boss_data[i].moving_way.second;
				if (boss_data[i].position.first >= width || boss_data[i].position.first < 0 ||
					boss_data[i].position.second >= height || boss_data[i].position.second < 0) {
					boss_data[i].is_alive = false;
					boss_amount--;
				}
			}
		}
		for (i = 0;i < boss_data.size();i++) {
			if (boss_data[i].is_alive) {
				if (bomb_map[boss_data[i].position.first][boss_data[i].position.second].first == true) {
					bomb_map[boss_data[i].position.first][boss_data[i].position.second].second = true;
					boss_data[i].is_alive = false;
					boss_amount--;
				}
			}
		}
		for (i = 0;i < width;i++) {
			for (j = 0;j < height;j++) {
				if (bomb_map[i][j].second == true) {
					bomb_map[i][j].first = false;
					bomb_map[i][j].second = false;
				}
			}
		}
	}
	// outputs
	k = 0;
	for (i = 0;i < width;i++) {
		for (j = 0;j < height;j++) {
			if (bomb_map[i][j].first == true) {
				k++;
			}
		}
	}
	cout << k <<endl;
	return 0;
}