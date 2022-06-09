#include <bits/stdc++.h>
using namespace std;

struct relay_station{
	int l = false, r, w_l = 0, w_r = 0;
};

int updateRelayer(vector<relay_station> *R, int s) {
	if (!(*R)[s].l) {
		return (*R)[s].w_l;
	}
	(*R)[s].w_l = updateRelayer(R, (*R)[s].l);
	(*R)[s].w_r = updateRelayer(R, (*R)[s].r);
	return (*R)[s].w_l + (*R)[s].w_r;
}

int putPackage(vector<relay_station> *R, int start, int w) {
	if (!(*R)[start].l) {
		return start + 1;
	}
	if ((*R)[start].w_l > (*R)[start].w_r) {
		(*R)[start].w_r += w;
		return putPackage(R, (*R)[start].r, w);
	} else {
		(*R)[start].w_l += w;
		return putPackage(R, (*R)[start].l, w);
	}
}

int main() {
	int N_container, N_package, i, j, p, q, r;
	scanf("%d%d", &N_container, &N_package);
	vector<int> package(N_package);
	vector<relay_station> relayer(2 * N_container - 1);
	vector<bool> tracer(2 * N_container - 1, false);
	for (i = N_container - 1;i < 2 * N_container - 1;i++) scanf("%d", &relayer[i].w_l);
	for (i = 0;i < N_package;i++) scanf("%d", &package[i]);
	for (i = 0;i < N_container - 1;i++) {
		scanf("%d%d%d", &p, &q, &r);
		p--;q--;r--;
		relayer[p].l = q;
		relayer[p].r = r;
		tracer[q] = true;
		tracer[r] = true;
	}
	for (i = 0;i < 2 * N_container - 1;i++) {
		if (!tracer[i]) {
			j = i;
			break;
		}
	}
	updateRelayer(&relayer, j);
	for_each(package.begin(), package.end(), [&j, &relayer](int p){printf("%d ", putPackage(&relayer, j, p));});


	// for (i = 0;i < 2 * N_container - 1;i++) {
	// 	printf("%d %d %d %d\n", relayer[i].l, relayer[i].r, relayer[i].w_l, relayer[i].w_r);
	// }
	// cin >> i;
	return 0;
}