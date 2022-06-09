#include<bits/stdc++.h>
using namespace std;

void debug(vector<int> a) {for (int i = 0;i < (int)a.size();i++)cout << a[i] << ' ';cout << endl;}

int main() {
	int n;
	while (cin >> n){
		int want, i;
		scanf("%d", &want);
		vector<int> cows(n), prefix_sum(n);
		for (i = 0;i < n;i++) scanf("%d", &cows[i]);
		for (i = 0;i < want;i++) cows.push_back(cows[i]);
		int maxima = 0, now = 0;
		for (i = 0;i < want;i++) now += cows[i];
		maxima = now;
		for (i = want;i < (int)cows.size();i++) {
			now += cows[i] - cows[i - want];
			maxima = max(now, maxima);
		}
		cout << maxima << endl;
	}
}
