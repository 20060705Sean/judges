#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int f(int x) {return x * x + x + 41;}

bool is_prime(int x) {
	for (int i = 2;i <= (int)sqrt(x);i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	vector<int> prime_amount(10002);
	int a, b, count_prime = 0;
	for (int i = 0;i <= 10000;i++) {
		if(is_prime(f(i))) count_prime++;
		prime_amount[i + 1] = count_prime;
	}
	while (scanf("%d", &a) != EOF) {
		scanf("%d", &b);
		printf("%.2f\n", ((float)(prime_amount[b + 1] - prime_amount[a]) * 100 / (float)(b - a + 1) + 0.000001));
	}
}
