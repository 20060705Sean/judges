#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int i, j;
		const int m = n;
		bitset<m> bst;
		int large = pow(2, m);
		int pivot;
		bool flag;
		for (i = 0;i < large;i++) {
			bst = bitset<m>(i);
			pivot = 0;
			flag = false;
			for (j = 0;j < m;j++) {
				if (bst[j]) { // (
					pivot++;
				} else { // )
					if (pivot == 0) {
						flag = true;
						break;
					}
					pivot--;
				}
			}
			if (!flag&&pivot == 0) {
				for (j = 0;j < m;j++) {
					if (bst[j]) printf("%c", '(');
					else printf("%c", ')');
				}
				printf("%s", "\n");
			}
		}
	}
}