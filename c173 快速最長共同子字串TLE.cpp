#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(, string S, string T) {
	vector<vector<int>>L(S.size() + 1, vector<int>(T.size() + 1, 0));
	int i, j;
	for (i = 0;i < (int)S.size();i++) {for (j = 0;j < (int)T.size();j++) {
		L[i + 1][j + 1] = (S[i] == T[j])? L[i][j] + 1: max(L[i][j + 1], L[i + 1][j]);
	}}
	return L[S.size()][T.size()];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B;
	while (cin >> A) {
		cin >> B;
		printf("%d\n", longestCommonSubstring(A, B));
	}
}

