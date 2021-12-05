#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    ll n,H;
    ll a[1005];
    while(t--){
        cin>>n>>H;
        for(ll i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        ll ans=0;
        ll damage=a[n-1]+a[n-2];
        ans+=(H/damage)*2;
        H%=damage;
        if(H==0)
            ans+0;
        else if(H-a[n-1]<=0)
            ans++;
        else ans+=2;
        cout<<ans<<endl;
    }
    return 0;
}
