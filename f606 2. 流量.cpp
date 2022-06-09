#include <bits/stdc++.h>
using namespace std;
int main() {
	// Vars and inputs
	int server_amount, city_amount, query_amount, server, city, position, summary, minimum_summary, i, j, k;
	cin >> server_amount >> city_amount >> query_amount;
	vector<vector<int>> server_to_city_stream_amount(server_amount, vector<int>(city_amount, 0)), 
		city_to_city_stream_amount(city_amount, vector<int>(city_amount, 0));
	for (i = 0;i < server_amount;i++) { for (j = 0;j < city_amount;j++) {
		cin >> server_to_city_stream_amount[i][j];
	}}
	// Calculations
	minimum_summary = 10000000;
	while (query_amount--) {
		summary = 0;
		for (i = 0;i < city_amount;i++) {
			for (j = 0;j < city_amount;j++) {
				city_to_city_stream_amount[i][j] = 0;
			}
		}
		for (server = 0;server < server_amount;server++) {
			cin >> position;
			for (city = 0;city < city_amount;city++) {
				city_to_city_stream_amount[position][city] += server_to_city_stream_amount[server][city];
			}
		}
		for (i = 0;i < city_amount;i++) {
			for (j = 0;j < city_amount;j++) {
				if (i == j) summary += city_to_city_stream_amount[i][j];
				else {
					k = city_to_city_stream_amount[i][j];
					if (k < 1000) summary += 3 * k;
					else summary += 2 * k + 1000;
				}
			}
		}
		minimum_summary = min(minimum_summary, summary); 
	}
	// Output
	cout << minimum_summary;
	return 0;
}