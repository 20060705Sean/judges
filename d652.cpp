#include <bits/stdc++.h>
using namespace std;


// m  -  -1
// |     |
// +1 -  0
/*
1 2 3 4 5

   0  1  2  3  4
0  0
1  0  0
2  6  0  0
3  18 24 0  0
4  38 66 60 0  0

P(i,j)=在(i,j)內所有怪物都被吃完所產生的最小污染
P(i,j)閉區間內都吃完所產生最小汙染=找到k在[i+1,j-1]中使得P(i,k)+P(k,j)+p[i]*p[j]*p[k]最小

*/

int main() {
	// Vars and inputs
	int amount_of_monsters, i, j, k;
	cin >> amount_of_monsters;
	vector<int> weight_of_monsters(amount_of_monsters, 0);
	vector<vector<int>> dp_array(amount_of_monsters, vector<int>(amount_of_monsters, 0));
	// make dp_array lower triangular matrix
	for (i = 0;i < amount_of_monsters;i++) cin >> weight_of_monsters[i];
	// Calculation
	for (i = 2;i < amount_of_monsters;i++) {
		for (j = i - 2;j > -1;j--) {
			dp_array[i][j] = dp_array[i][j + 1] + dp_array[j + 1][j] + weight_of_monsters[j] * weight_of_monsters[j + 1] * weight_of_monsters[i];
			for (k = j + 2;k < i;k++) dp_array[i][j] = min(dp_array[i][j], dp_array[i][k] + dp_array[k][j] + weight_of_monsters[j] * weight_of_monsters[k] * weight_of_monsters[i]);
		}
	}
	cout << dp_array[amount_of_monsters - 1][0];
	return 0;
}