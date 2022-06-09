#include <bits/stdc++.h>
using namespace std;

int main() {
	// vars and inputs
	int N, num = 0, i;
	vector<int> Seq(10000);
	vector<int>::iterator itr;
	// calculations
	while (cin >> N) {
		for (i = 0;i < N;i++) cin >> Seq[i];
		itr = Seq.begin();
		for_each(Seq.begin(), Seq.end(), [&Seq, &itr, &num](int k){
			for_each(itr, Seq.end(), [&num, &k](int m){
				if (m > k) num++;
			});
			itr++;
		});
		cout << "Minimum exchange operations : " << num << endl;
		num = 0;
	}
	// outputs
	return 0;
}