// https://drive.google.com/file/d/1RSq17g00V-ygkC8x37iLhtNteoqLAwZg/view

/*

input(G)
for each vertex:calculate_degree
sort_by_degree


*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

struct vertex {
	vector<pair<int, int>> connection;
	int deg, bikes, self;
	bool operator<(vertex &that) {
		return this->deg < that.deg;
	}
};

void debug_graph(vector<vertex> a) {
	for (int i = 0;i < (int)a.size();i++) {
		cout << a[i].self << ':' << endl;
		for (int j = 0;j < (int)a[i].connection.size();j++) {
			cout << '\t' << a[i].connection[j].first << '_' << a[i].connection[j].second << ' ';
		}
		cout << endl;
		cout << '\t' << a[i].deg << ' ' << a[i].bikes << endl;
	}
}
template<typename T>
void debug_vec(T a) {
	for (int i = 0;i < (int)a.size();i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	int n, k, i, a, b, c;
	scanf("%d%d", &n, &k);
	priority_queue<vertex>
	vertex v;
	vector<bool> visit(n);
	for (i = 0;i < n;i++) {
		scanf("%d", &graph[i].bikes);
		graph[i].self = i;
	}
	for (i = 1;i < n;i++) {
		scanf("%d%d%d", &a, &b, &c);
		a--;b--;
		graph[a].connection.push_back({b, c});
		graph[b].connection.push_back({a, c});
	}
	for (i = 0;i < n;i++) graph[i].deg = graph[i].connection.size();
	sort(graph.begin(), graph.end());
	debug_graph(graph);
	cin >> i;
}