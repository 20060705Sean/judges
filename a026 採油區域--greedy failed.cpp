#include <bits/stdc++.h>
using namespace std;

struct area_sum {
	int x, y, value;
};

int main() {
	int m, n, k, i, j, p;
	scanf("%d%d%d", &m, &n, &k);
	vector<vector<int>> num(m, vector<int>(n));
	vector<area_sum> calculate_vec;
	area_sum q; 
	for (i = 0;i < m;i++) {for (j = 0;j < n;j++) {scanf("%d", &num[i][j]);}}
	for (i = 0;i < m;i++) {for (j = 0;j < n - k + 1;j++) {
		for (p = 1;p < k;p++) num[i][j] += num[i][j + p];
	}}
	for (j = 0;j < n - k + 1;j++) {for (i = 0;i < m - k + 1;i++) {
		for (p = 1;p < k;p++) num[i][j] += num[i + p][j];
		q.x = i;
		q.y = j;
		q.value = num[i][j];
		calculate_vec.push_back(q);
	}}
	sort(calculate_vec.begin(), calculate_vec.end(), [](area_sum a, area_sum b){
		return a.value > b.value;
	});
	int x_1, y_1, x_2, y_2, sum;
	x_1 = calculate_vec[0].x, y_1 = calculate_vec[0].y, sum = calculate_vec[0].value;
	for (i = 1;i < calculate_vec.size();i++) {
		if (abs(x_1 - calculate_vec[i].x) >= k + 1 || abs(y_1 - calculate_vec[i].y) >= k + 1) {
			x_2 = calculate_vec[i].x, y_2 = calculate_vec[i].y;
			sum += calculate_vec[i].value;
			cout << calculate_vec[i].value <<' ';
			break;
		}
	}
	for (;i < calculate_vec.size();i++) {
		if (abs(x_1 - calculate_vec[i].x) >= k + 1 || abs(y_1 - calculate_vec[i].y) >= k + 1) {
			if (abs(x_2 - calculate_vec[i].x) >= k + 1 || abs(y_2 - calculate_vec[i].y) >= k + 1) {	
				sum += calculate_vec[i].value;
			cout << calculate_vec[i].value <<' ';
				break;
			}
		}	
	}
	cout << sum << ' ' << x_1 << ' ' << y_1 << ' ' << x_2 << ' ' << y_2;
	for (i = 0; i< calculate_vec.size();i++) cout << calculate_vec[i].x << ' '<< calculate_vec[i].y << ' ' << calculate_vec[i].value << endl;
	// for (i = 0;i < m;i++) {
	// 	for (j = 0;j < n;j++) {
	// 		cout << num[i][j] << '\t';
	// 	}
	// 	cout <<endl;
	// }
	cin >> n;
}