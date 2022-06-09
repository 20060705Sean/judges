#include<bits/stdc++.h>
using namespace std;


struct strvv{
	string s;
	bool operator< (const strvv other) const {
		return other.s + s < s + other.s;
	}
};

void debug(priority_queue<strvv> a) {
	cout << endl;
	while (!a.empty()) {
		cout << a.top().s << ' ';a.pop();
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);//cout.tie(0);
	//strvv a = {"285"}, b = {"2851"};
	//cout << (a < b);
	int n, i;
	while (cin >> n) {
		vector<strvv> A(n);
		for (i = 0;i < n;i++) cin >> A[i].s;
		sort(A.begin(), A.end());
		for (i = 0;i < n;i++) cout << A[i].s;
		//priority_queue<strvv> pq(A.begin(), A.end());
		//while (!pq.empty()) {
		//	cout << pq.top().s << ' ';pq.pop();
		//}
		cout << '\n';
	}
}
