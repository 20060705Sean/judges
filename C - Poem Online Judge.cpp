#include <bits/stdc++.h>
using namespace std;
struct poem {
	string a;
	int sc, id;
};
int main() {
	map<string, pair<int, int>> scores;
	int i, N, T;
	string S;
	scanf("%d", &N);
	for (i = 0;i < N;i++) {
		cin >> S;
		scanf("%d", &T);
		if (!(scores[S].first)) scores[S] = {T, i};
	}
	map<string, pair<int, int>>::iterator M = scores.begin();
	int idx = 0, big = 0;
	for (i = 0;i < (int)scores.size();i++) {
		if ((*M).second.first > big) {
			idx = (*M).second.second;
			big = (*M).second.first;
		}
		M++;
	}
	cout << idx + 1;
}