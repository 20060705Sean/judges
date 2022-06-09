#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate_left_matrix(vector<vector<int>> mat) {
	int i, j, k = mat[0].size() - 1;
	vector<vector<int>> new_matrix(mat[0].size(), vector<int>(mat.size(), 0));
	for (i = 0;i < mat.size();i++) {
		for (j = 0;j < mat[0].size();j++) {
			new_matrix[k - j][i] = mat[i][j];
		}
	}
	return new_matrix;
}

vector<vector<int>> flip_matrix(vector<vector<int>> mat) {
	vector<vector<int>> new_matrix;
	for_each(mat.rbegin(), mat.rend(), [&new_matrix](vector<int> m){
		new_matrix.push_back(m);
	});
	return new_matrix;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int row, column, queries, i, j;
	while (cin >> row) {
		cin >> column >> queries;
		vector<int> query(queries);
		vector<vector<int>> matrix(row, vector<int>(column, 0));
		for (i = 0;i < row;i++) {
			for (j = 0;j < column;j++) {
				cin >> matrix[i][j];
			}
		}
		for (i = 0;i < queries;i++) cin >> query[i];
		for_each(query.rbegin(), query.rend(), [&matrix](int k){
			if (k) matrix = flip_matrix(matrix);
			else matrix = rotate_left_matrix(matrix);
		});
		cout << matrix.size() << ' ' << matrix[0].size() << endl;
		for_each(matrix.begin(), matrix.end(), [&i, &j](vector<int> k) {
			for_each(k.begin(), k.end() - 1, [](int q) {
				cout << q << ' ';
			});
			i++;
			cout << k[k.size() - 1] << endl;
		});
	}
	return 0;
}
