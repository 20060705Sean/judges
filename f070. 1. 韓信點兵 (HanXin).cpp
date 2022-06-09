#include <bits/stdc++.h>
using namespace std;
int main() {
	const int M= 2 * 10*10*10*10*10*10;
	int i,a,b,c,p,q,r;
	scanf("%d%d%d%d%d%d",&a,&p,&b,&q,&c,&r);
	for (i=2;i < M;i++) {
		if (i % a == p) {
			if (i % b == q) {
				if (i % c == r) {
					cout << i;
					break;
				}
			}
		}
	}
	return 0;
}