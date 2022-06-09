#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int k;
	bitset<32> AA;
	while (cin >> k) {
		AA = k;
		if (AA.count() == 1) printf("Yes\n");
		else printf("No\n");
	}
}
