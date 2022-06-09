#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int N, i, j, the_first_adder, the_second_adder;
	cin >> N;
	cin.ignore();
	int chart[10] = {0,2,4,6,8,1,3,5,7,9};
	string the_code;
	for (i = 0;i < N;i++) {
		getline(cin, the_code);
		the_first_adder = 0;the_second_adder = 0;
		for (j = 15;j >= 0;j--) {
			if (j % 2) the_second_adder += the_code[j + j / 4] - '0';
			else the_first_adder += chart[the_code[j + j / 4] - '0'];
		}
		if (!((the_first_adder + the_second_adder) % 10)) cout << "Valid" << endl;
		else cout << "Invalid" << endl;
	}
	return 0;
}