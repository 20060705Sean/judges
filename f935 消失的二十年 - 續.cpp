#include<bits/stdc++.h>
using namespace std;

void debug_vec(vector<int> a){for(int i=0;i<(int)a.size();i++)cout<<a[i]<<' ';cout<<endl;}

vector<int> input_data(void) {
	string input;
	stringstream buffer;
	int temp;
	vector<int> price;
	getline(cin, input);
	buffer << input;
	while (true) {
		buffer >> temp;
		if (buffer.fail()) break;
		price.push_back(temp);
	}
	return price;
}

int main() {
	vector<int> price = input_data(), delta_price;
	int n = price.size(), i, best_sum = 0, current_sum = 0, best_start = 0, best_end = 0, current_start;
	for (i = 0;i < n - 1;i++) delta_price.push_back(price[i + 1] - price[i]);
	for (i = 0;i < n - 1;i++) {
		if (current_sum <= 0) current_start = i, current_sum = delta_price[i];
		else current_sum += delta_price[i];
		if (current_sum > best_sum) best_sum = current_sum, best_start = current_start, best_end = i + 1;
	}
	printf("%d %d %d", best_sum, (best_sum)?price[best_start]:-1, (best_sum)?price[best_end]:-1);
	return 0;
}
