#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,l,q;
	while(cin>>n>>m>>l>>q){
		int r[m][2]; // to store relationships
		for(int i=0;i<m;i++){
			cin>>r[i][0]>>r[i][1];
		}
		vector<int> p; // where problem is
		int k;
		for(int i=0;i<l;i++){
			cin>>k;
			p.push_back(k);
		}
		k=0;
		while(k!=1){
			for(int i=0;i<p.size();i++){
				for(int j=0;j<m;j++){
					if(p[i]==r[j][0]){
						p.push_back(r[j][1]);
						r[j][0]=-1;
						k=0;
					} else {
						k=1;
					}
				}
			}
		}
		int s;
		for(int i=0;i<q;i++){
			cin >>s;
			k=0;
			for(int j=0;j<p.size();j++){
				if(s==p[j]){
					k=1;
					break;
				}
			}
			if(k){
				cout<<"TUIHUOOOOOO\n";
			}else{
				cout<<"YA~~\n";
			}
		}
	}
}