#include <iostream>
#include <stack>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		while(1){
			int k[n],i,p=1;
			stack<int> s;
			cin>>k[0];
			if(k[0]==0)break;
			for(i=1;i<n;i++)cin>>k[i];
			for(i=0;i<n;i++){
				if(!s.empty()&&s.top()==k[i])s.pop();
				else if(k[i]>=p){
					for(int l=p;l<k[i];l++)s.push(l);
					p=k[i]+1;
				}else break;
			}
			if(i==n)cout<<"Yes\n";
			else cout<<"No\n";
		}
		cout<<"\n";
	}
	return 0;
}