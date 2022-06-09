#include<bits/stdc++.h>
using namespace std;

int main() {
	int Q, t, x, c;scanf("%d", &Q);
	multiset<int> mul;
	while (Q--) {
		scanf("%d", &t);
		switch(t) {
			case (1): {
				scanf("%d", &x);
				mul.insert(x);
				break;
			}
			case (2): {
				scanf("%d%d", &x, &c);
				while (c-- && mul.find(x) != mul.end()) {
					mul.erase(mul.find(x));
				}
				break;
			}
			case (3): {
				printf("%d\n", *mul.rbegin() - *mul.begin());
				break;
			}
		}
	}
}
