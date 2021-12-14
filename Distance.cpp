#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int a,b;
    while(t--){
        cin>>a>>b;
        int dians=a+b;
        if(dians%2)
            cout<<"-1 -1\n";
        else if(a%2)
            cout<<(a+1)/2<<" "<<(b-1)/2<<"\n";
        else
            cout<<a/2<<" "<<b/2<<"\n";
    }
    return 0;
}
