#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    ll a[105];
    while(t--){
        int bars,l,h,budget;
        cin>>bars>>l>>h>>budget;
        for(int i=0;i<bars;i++)
            cin>>a[i];
        sort(a,a+bars);
        int type=0;
        for(int i=0;i<bars;i++){
            if(budget>=a[i]&&a[i]>=l&&a[i]<=h){
                budget-=a[i];
                type++;
            }
        }
        cout<<type<<endl;
    }
    return 0;
}
