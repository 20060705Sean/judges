#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long total_length, segment_length, summary = 0, i;
	string color;
	cin >> segment_length >> total_length;
	pair<string, long long> in;
	map<string, long long> color_map;
	for (i = 0;i < segment_length;i++) {
		cin >> color;
		in.first = color;
		in.second = i;
		color_map.insert(in);
	}
	for (i = segment_length;i < total_length;i++) {
		if (color_map.size() == segment_length) summary++;
		color_map.erase((*color_map.begin()).first);
		cin >> color;
		in.first = color;
		in.second = i;
		color_map.insert(in);
	}
	if (color_map.size() == segment_length) summary++;
	cout << summary;
	cin >> summary;
	return 0;
}