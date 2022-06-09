#include <bits/stdc++.h>
using namespace std;

/*
有 N ≤ 10^6 棟房子由左至右排成一列。第 i 棟房子的高度是 Hi。如果 a < b 而
且第 a 棟房子和第 b 棟房子之間沒有其它房子高度超過 Ha 或 Hb，那麼從第 a 棟房子
可以看得到第 b 棟房子，從第 b 棟房子也可以看到第 a 棟房子。如果從第 i 棟房子能
看見的房子數為 Ci，求 C1 + C2 + · · · + CN。

想法：從第i棟往左右搜尋，直到搜到一個比他高的，算出中間棟數
*/
int main() {
	int n, i, k;
	long long sum = 0;
	scanf("%d", &n);
	stack<int> stk, cnt;
	// stk is for recording the heights, cnt is for counting amount
	for (i = 0;i < n;i++) {
		scanf("%d", &k);
		while (!stk.empty() && stk.top() < k) {
			sum += cnt.top();
			cnt.pop();
			stk.pop();
			// Why we can just throw the information out?
			// -->cos' the lower houses are going to be obscured by this one
		}
		if (!stk.empty() && stk.top() == k) {
			sum += cnt.top();
			cnt.top()++;
			// Here is going to process the same height problem
		} else {
			stk.push(k);
			cnt.push(1);
		}
		if (stk.size() > 1) {
			sum++;
			// you can always see the highest(farest) one, the while loop won't count it in
		}
	}
	cout << sum * 2;
}