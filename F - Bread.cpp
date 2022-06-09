#include<bits/stdc++.h>
using namespace std;

/*
朝「現在最小花費」是最好的
*/

void debug(priority_queue<long long, vector<long long>, greater<long long>> a) {
	cout << endl;
	while (!a.empty()) {
		cout << a.top() << ' ';a.pop();
	}
	cout << endl;
}

int main() {
	int i, N;long long L, temp, sum = 0;scanf("%d%lld", &N, &L);
	vector<long long> A(N);
	for (i = 0;i < N;i++) {
		scanf("%lld", &A[i]);
		sum += A[i];
	}
	if (L != sum) A.push_back(L - sum);
	sum = 0;
	priority_queue<long long, vector<long long>, greater<long long>> loaf(A.begin(), A.end());
	while (loaf.size() != 1) {
		temp = loaf.top();loaf.pop();
		temp += loaf.top();loaf.pop();
		sum += temp;
		loaf.push(temp);
	}
	printf("%lld", sum);
}

