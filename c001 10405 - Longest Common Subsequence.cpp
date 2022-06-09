#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

// DP Time O(nm) Space O(nm)
vector<char> LongestCommonSubsequence(vector<char> seq1, vector<char> seq2) {
	vector<vector<int>> numbers(seq1.size() + 1, vector<int> (seq2.size() + 1, 0));
	vector<vector<int>> directions(seq1.size() + 1, vector<int> (seq2.size() + 1, 2));
	int idx_1 = 1, idx_2;
	for_each(seq1.begin(), seq1.end(), [&seq2, &numbers, &directions, &idx_1, &idx_2](char n1) {
		idx_2 = 1;
		for_each(seq2.begin(), seq2.end(), [&numbers, &directions, &n1, &idx_1, &idx_2](char n2) {
			if (n1 == n2) {
				numbers[idx_1][idx_2] = numbers[idx_1 - 1][idx_2 - 1] + 1;
				directions[idx_1][idx_2] = 0;
			} else if (numbers[idx_1 - 1][idx_2] >= numbers[idx_1][idx_2 - 1]) {
				numbers[idx_1][idx_2] = numbers[idx_1 - 1][idx_2];
				directions[idx_1][idx_2] = 1;
			} else {
				numbers[idx_1][idx_2] = numbers[idx_1][idx_2 - 1];
				directions[idx_1][idx_2] = -1;
			}
			idx_2++;
		});
		idx_1++;
	});
	idx_1--;idx_2--;
	vector<char> result;
	int dir = directions[idx_1][idx_2];
	while (dir != 2) {
		if (dir == 0) {
			result.push_back(seq1[idx_1 - 1]);
			dir = directions[--idx_1][--idx_2];
		} else {
			dir = (dir == 1) ? directions[--idx_1][idx_2] : directions[idx_1][--idx_2];
		}
	}
	return result;
}
int main() {
	// ios::sync_with_stdio(false);cin.tie(0);
	string m;
	const char *c;
	c = m.c_str();
	while(cin >> m) {
		vector<char> a(c, c + sizeof(c) / sizeof(char));
		cin >> m;
		vector<char> b(c, c + sizeof(c) / sizeof(char));
		for_each(a.begin(), a.end(), [](char k) {
			cout << k << ' ';
		});
		cout << endl;
		for_each(b.begin(), b.end(), [](char k) {
			cout << k << ' ';
		});

		cout << LongestCommonSubsequence(a, b).size() << endl;
	}
	return 0;
}