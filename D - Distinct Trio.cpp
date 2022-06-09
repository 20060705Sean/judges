#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j, k;
	long long sum = 0;
	scanf("%d", &n);
	vector<int> num(n, 0);
	for (i = 0;i < n;i++) {
		scanf("%d", &num[i]);
	}
	for (i = 0;i < n - 2;i++) {
		for (j = i + 1;j < n - 1;j++) {
			if (num[i] ^ num[j]) {
				if (i ^ j) {
					for (k = j + 1;k < n;k++) {
						if (num[i] ^ num[k]) {
							if (num[j] ^ num[k]) {
								if (i ^ k) {
									if (j ^ k) {
										sum++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d", sum);
}
