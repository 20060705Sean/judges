#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, i;
	cin >> n;
	vector<int> score(n);
	for (i = 0;i < n;i++) cin >> score[i];
	sort(score.begin(), score.end());
	for_each(score.begin(), score.end(), [](int k){cout << k << ' ';});
	cout << endl;
	if (score[0] >= 60) cout << "best case" << '\n' << score[0];
	else if(score[score.size() - 1] < 60) cout << score[score.size() - 1] << '\n' << "worst case";
	else {
		;
		for (int pivot = 0;pivot < n;pivot++) {
			if (score[pivot] < 60 && score[pivot + 1] >= 60) {
				cout << score[pivot] << '\n' << score[pivot + 1];
				break;
			}
		}
	}
	cin >> n;
	return 0;
}