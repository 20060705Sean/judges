#include<bits/stdc++.h>
using namespace std;

struct Node{
	bool is_teminated = true;
	char value;
	vector<Node> child;
};

int main() {
	int N;scanf("%d", &N);
	char c;
	Node head, now;
	head.value = ' ';
	head.is_teminated = false;
	head.child.resize(130);
	getchar();
	while (N--) {
		now = head;
		while (1) {
			c = getchar();
			if (c == '\n') break;
			now = now.child[(int)c];
			now.is_teminated = false;
			now.value = c;
			now.child.resize(130);
		}
	}
	return 0;
}
