#include<bits/stdc++.h>
using namespace std;

int count_it(int init, int val) {
	int sum = 0;
	while (init >= val) {
		sum += init / val;
		init = (init % val) + (init / val);
	}
	return sum;
}

int main() {
	int N, i, p, q, r;scanf("%d", &N);
	for (i = 0;i < N;i++) {
		scanf("%d%d%d", &p, &q, &r);
		printf("%d\n", count_it(p + q, r));
	}
}
