#include <bits/stdc++.h>
using namespace std;

struct Box {
	int weight;
	int use_time;
};

bool cmp(Box A, Box B){
	return A.weight * B.use_time - B.weight * A.use_time < 0;
}

int main() {
	long N, i, weight_sum = 0;
	long long energy_consume = 0;
	scanf("%ld", &N);
	Box boxes[N];
	for (i = 0;i < N;i++) scanf("%d", &boxes[i].weight);
	for (i = 0;i < N;i++) scanf("%d", &boxes[i].use_time);
	sort(boxes, boxes+N, cmp);
	for (i = 0;i < N;i++) {
		energy_consume += weight_sum * boxes[i].use_time;
		weight_sum += boxes[i].weight;
	}
	printf("%lld", energy_consume);
	return 0;
}

