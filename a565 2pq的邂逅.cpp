#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, i, sum, waiting;scanf("%d", &n);getchar();
	char c;
	for (i = 0;i < n;i++) {
		sum = 0;waiting = 0;
		while ((c = getchar()) != '\n') {
			if (c == 'p') {
				waiting++;
			} else if (c == 'q') {
				if (waiting != 0) {
					waiting--;sum++;
				}
			}
		}
		printf("%d\n", sum);
	}
}
