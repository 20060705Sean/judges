#include <bits/stdc++.h>
using namespace std;
#define node pair<int, vector<int>>
int dfs(vector<node> &tr,vector<int> &alr,int rt,int length){
	*alr[rt]=true;
	for_each(tr[rt].second.begin(),tr[rt].second.end(),[](int q){if(!*alr[q]){dfs(tr,alr,q,length+1)}});
}
int main() {
	// input and set
	int i,j,k,n,root;
	while(cin>>n){
		node c={-1,{}};
		vector<node> tree(n,c);
		for(i=0;i<n-1;i++){
			cin>>j>>k;
			tree[j].second.push_back(k);
			tree[k].first=j;
		}
		// find root O(k), k<=n
		for(i=0;i<n;i++){if(tree[i].first==-1){root=i;break;}}
		// prepare to dfs O(n)
		for(i=0;i<n;i++){tree[i].second.push_back(tree[i].first);}
		// dfs for deepest root
		vector<bool> already(n,false);
		already[root]=true;
		int idx=dfs(&tree,&already,root,0);
		for(i=0;i<n;i++){for(j=0;j<tree[i].second.size();j++){cout<<tree[i].second[j]<<' ';}cout<<endl;}
	}
	//
	cin>>n;
	//
	return 0;
}