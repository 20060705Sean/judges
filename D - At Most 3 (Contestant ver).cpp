#include <bits/stdc++.h>
using namespace std;

void debug(vector<int> a) {
	for (int i = 0;i < (int)a.size();i++) {
		printf("%d ", a[i]);
	}
}

int main() {
	vector<int> weights;
	int i;
	for (i = 1;i < 100;i++) weights.push_back(i);
	for (i = 100;i < 10000;i += 100) weights.push_back(i);
	for (i = 10000;i <= 1000000;i += 10000) weights.push_back(i);
	printf("%d\n", weights.size());
	debug(weights);
}
