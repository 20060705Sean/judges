// learn English: labyrinth n.迷宮

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second
template <typename T>
void debug_2dvec(vector<vector<T>> A) {
	for (int i = 0;i < (int)A.size();i++) {for (int j = 0;j < (int)A[i].size();j++) {
		cout << A[i][j] << ' ';
	}cout << endl;}
}
template <typename T>
void debug_vec(vector<T> A) {
	for (int i = 0;i < (int)A.size();i++) cout << A[i] << ' ';
}
/*
«+» means this block has 4 doors (one door to each neighbouring block);
«-» means this block has 2 doors — to the left and to the right neighbours;
«|» means this block has 2 doors — to the top and to the bottom neighbours;
«^» means this block has 1 door — to the top neighbour;
«>» means this block has 1 door — to the right neighbour;
«<» means this block has 1 door — to the left neighbour;
«v» means this block has 1 door — to the bottom neighbour;
«L» means this block has 3 doors — to all neighbours except left one;
«R» means this block has 3 doors — to all neighbours except right one;
«U» means this block has 3 doors — to all neighbours except top one;
«D» means this block has 3 doors — to all neighbours except bottom one;
«*» means this block is a wall and has no doors;
*/
struct status{
	pii pos;
	int direction, step;
};
// for pre-setting
map<char, char> chart1 = {
	{'+', '+'}, {'-', '|'}, {'|', '-'}, {'^', '>'}, {'>', 'v'}, {'v', '<'}, 
	{'<', '^'}, {'L', 'U'}, {'U', 'R'}, {'R', 'D'}, {'D', 'L'}, {'*', '*'}
};
map<char, vector<bool>> chart2 = {
	{'+', {1, 1, 1, 1}}, {'-', {0, 1, 0, 1}}, {'|', {1, 0, 1, 0}}, 
	{'^', {1 ,0, 0, 0}}, {'>', {0, 1, 0, 0}}, {'v', {0, 0, 1, 0}}, 
	{'<', {0, 0, 0, 1}}, {'L', {1, 1, 1, 0}}, {'U', {0, 1, 1, 1}}, 
	{'R', {1, 0, 1, 1}}, {'D', {1, 1, 0, 1}}, {'*', {0, 0, 0, 0}}
};
vector<vector<char>> rotate(vector<vector<char>> a) {
	int i, j;
	for (i = 0;i < (int)a.size();i++) {
		for (j = 0;j < (int)a[i].size();j++) {
			a[i][j] = chart1[a[i][j]];
		}
	}
	return a;
}
int main() {
	// vars and inputs
	int m, n, i, j, x, y; scanf("%d%d", &m, &n);
	vector<vector<char>> labyrinth(m + 2, vector<char>(n + 2, '*'));getchar();
	for (i = 1;i <= m;i++) {for (j = 1;j <= n;j++) {
		scanf("%c", &labyrinth[i][j]);
	}getchar();}
	pii start, end;cin >> start.f >> start.s >> end.f>> end.s;//scanf("%d%d%d%d", &start.f, &start.f, &end.s, &end.s);
	vector<vector<char>> labyrinth_status[4];
	labyrinth_status[0] = labyrinth;
	labyrinth_status[1] = rotate(labyrinth_status[0]);
	labyrinth_status[2] = rotate(labyrinth_status[1]);
	labyrinth_status[3] = rotate(labyrinth_status[2]);
	// execution
	vector<vector<vector<bool>>> ways(m + 2, vector<vector<bool>>(n + 2, vector<bool>((4))));
	vector<vector<bool>> does_here_vis(m + 2, vector<bool>(n + 2, true));
	queue<status> bfs;
	bfs.push({start, 0, 0});
	int dir;
	vector<bool> up, down, right, left, here;
	while (1) {
		x = bfs.front().pos.f; y = bfs.front().pos.s;
		if (bfs.empty()) {
			cout << "-1";
			break;
		}
		if (x == end.f) {if (y == end.s) {
			printf("%d", bfs.front().step);
			break;
		}}
		dir = bfs.front().direction;
		here = chart2[labyrinth_status[dir][x][y]];
		up = chart2[labyrinth_status[dir][x - 1][y]];
		down = chart2[labyrinth_status[dir][x + 1][y]];
		right = chart2[labyrinth_status[dir][x][y + 1]];
		left = chart2[labyrinth_status[dir][x][y - 1]];
		if (here[0] && up[2]) bfs.push({{x - 1, y}, dir, bfs.front().step + 1});
		if (here[1] && left[3]) bfs.push({{x, y + 1}, dir, bfs.front().step + 1});
		if (here[2] && down[0]) bfs.push({{x + 1, y}, dir, bfs.front().step + 1});
		if (here[3] && right[1]) bfs.push({{x, y - 1}, dir, bfs.front().step + 1});
		if (dir != 3) bfs.push({{x, y}, dir + 1, bfs.front().step + 1});
		bfs.pop();
	}
	// end
	cin >> i;
}