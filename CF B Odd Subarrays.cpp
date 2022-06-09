#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, n, i, k, _max, _count;scanf("%d", &N);
	while (N--) {
		_max = 0;
		_count = 0;
		scanf("%d", &n);
		for (i = 0;i < n;i++) {
			scanf("%d", &k);
			if (_max < k) _max = k;
			else _max = 0, _count++;
		}
		printf("%d\n", _count);
	}
	return 0;
}
