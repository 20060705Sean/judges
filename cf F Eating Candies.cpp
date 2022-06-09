#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, i, s1, s2, e, e1, e2;
	scanf("%d", &n);
	deque<int> Q;
	while (n--){
		scanf("%d", &k);
		Q.resize(k);
		for (i = 0;i < k;i++) scanf("%d", &Q[i]);
		s1 = 0, s2 = 0, e1 = 0, e2 = 0, e = 0;
		while (!Q.empty()) {
			if (s1 < s2) {
				s1 += Q.front();
				Q.pop_front();
				e1++;
			} else {
				s2 += Q.back();
				Q.pop_back();
				e2++;
			}
			if (s1 == s2) {
				e = e1 + e2;
			}
		}
		printf("%d\n", e);
	}
	return 0;
}