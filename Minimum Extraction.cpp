#include<bits/stdc++.h>
using namespace std;

int main(){
    int t1;
    int t2;
    int a[200005];
    cin>>t1;
    while(t1){
        cin>>t2;
        for(int i=0;i<t2;i++)
            cin>>a[i];
        sort(a,a+t2,less<int>());
        int ans=a[0];
        for(int i=1;i<t2;i++){
            int ansp=a[i]-a[i-1];
            ans=max(ans,ansp);
        }
        cout<<ans<<endl;
        t1--;
    }
    return 0;
}
