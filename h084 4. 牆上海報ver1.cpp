#include <bits/stdc++.h>
using namespace std;

/*
有一個由 n 個木板所組成的柵欄，每個木板的高度為 h[1],h[2],...,h[n]，有 k 
張海報要張貼在柵欄上，每張海報的寬度為 w[1],w[2],⋯,w[n] 並且高度均為 1。
若要張貼海報在高度為 x 的高度，則第 i 張海報需要張貼在一個長度為 w[i] 的連
續並且高度都不小於 x 的木板上，且每張海報張貼的高度需要一致、按照順序並不能重
疊 (可以相連)。詢問最高可以貼到多高的位置。

第一行有兩個正整數 n,k，接下來一行有 n 個正整數代表每個木板的高度，最後一行有 k 個正整數代表每張海報的寬度。

5 1
6 3 7 5 1
3
>> 3

10 3
5 3 7 5 1 7 5 3 8 4
2 2 1
>> 5
*/

/*
keypoint:
高度需要一致、按照順序
*/

/*
他給的提示:greed, 二分搜
*/
int main() {
	int piece_of_fences, piece_of_posters, i, k, maxima_height = 0, lt, poster_counts;
	vector<int> height_of_fences, width_of_posters;
	cin >> piece_of_fences >> piece_of_posters;
	for (i = 0;i < piece_of_fences;i++) {
		cin >> k;
		if (k > maxima_height) maxima_height = k;
		height_of_fences.push_back(k);
	}
	for (i = 0;i < piece_of_posters;i++) {
		cin >> k;
		width_of_posters.push_back(k);
	}
	// Binary Search
	int L = 1, R = maxima_height, m;
	bool cram_success;
	while (L != R) {
		m = (L + R + 1) / 2;
		cram_success = false;
		lt = -1;
		poster_counts = 0;
		// try cram posters on height m
		for (i = 0; i < piece_of_fences;i++) {
			if (height_of_fences[i] < m) lt = i;
			else if (i - lt == width_of_posters[poster_counts]) {
				lt = i;
				poster_counts++;
				if (poster_counts == piece_of_posters) break;
			}
		}
		cram_success = (poster_counts == piece_of_posters);
		if (cram_success) L = m;
		else R = m - 1;
	}
	cout << L;
	cin >> L;
	return 0;
}