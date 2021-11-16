#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    ll a[205];
    while(t--){
        int n;
        int p;
        int ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++){
            p=a[i]-i-1;
            ans=max(ans,p);
        }
        cout<<ans<<endl;
    }
    return 0;
}
