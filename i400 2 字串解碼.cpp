#include<bits/stdc++.h>
using namespace std;

/*
因為操作完的字串只是原字串的一個排列紀錄原長為N的一個全相異字串其變換之映射，即可以構造其逆變換
*/

int n, m, i, pivot1, pivot2;
bitset<100> operation;
vector<int> origin_seq(100), new_seq(100);

void debug() {
	for (i = 0;i < n;i++) {
		cout << origin_seq[i] << ' ';
	}
	cout << endl;
}

void transformation() {
	if (operation.count() % 2) {
		if (n % 2) {
			pivot1 = 0;
			for (i = n / 2 + 1;i < n;i++,pivot1++) new_seq[pivot1] = origin_seq[i];
			new_seq[n / 2] = origin_seq[n / 2];pivot1++;
			for (i = 0;i < n / 2;i++,pivot1++) new_seq[pivot1] = origin_seq[i];
		} else {
			pivot1 = 0;
			for (i = n / 2;i < n;i++,pivot1++) new_seq[pivot1] = origin_seq[i];
			for (i = 0;i < n / 2;i++,pivot1++) new_seq[pivot1] = origin_seq[i];
		}
		origin_seq = new_seq;
	}
	pivot1 = 0;
	pivot2 = n - 1;
	for (i = 0;i < n;i++) {
		if (operation[i]) {
			new_seq[i] = origin_seq[pivot2];
			pivot2--;
		} else {
			new_seq[i] = origin_seq[pivot1];
			pivot1++;
		}
	}
	origin_seq = new_seq;
}

int main() {
	scanf("%d%d", &m, &n);
	char input[n];
	for (i = 0;i < n;i++) origin_seq[i] = i;
	while (m--) {
		scanf("%s", &input[0]);
		for (i = 0;i < n;i++) operation[i] = (input[i] == '0')?0:1;
		transformation();
	}
	string origin, result;
	result.resize(n);
	cin >> origin;
	for (i = 0;i < n;i++) {
		result[origin_seq[i]] = origin[i];
	}
	cout << result;
}
