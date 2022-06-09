#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, L, i, p, q;
	long long sum = 0;
	scanf("%d%d", &n, &L);
	vector<int> cut(L, 0);
	for (i = 0;i < n;i++) {
		scanf("%d%d", &p, &q);
		cut[q] = p;
	}
	set<int> node;
	node.insert(0);
	node.insert(L);
	for (i = 0;i < n;i++) {
		sum += *(node.upper_bound(cut[i])) - *(node.lower_bound(cut[i]));
		cout << *(node.upper_bound(cut[i])) << ' ' << *(node.lower_bound(cut[i]))  <<' ' << *(node.upper_bound(cut[i])) - *(node.lower_bound(cut[i]))<<endl;
	
		node.insert(cut[i]);}
	cout << sum;
	cin >> sum;
	return 0;
}