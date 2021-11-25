#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==b&&b==c){
            cout<<"1"<<" "<<"1"<<" "<<"1"<<endl;
            continue;
        }
        ll big1=max(a,b);
        ll big=max(c,big1);
        if(a==b&&b==big){
            cout<<"1"<<" "<<"1"<<" "<<big-c+1<<endl;
            continue;
        }
        if(c==b&&b==big){
            cout<<big-a+1<<" "<<"1"<<" "<<"1"<<endl;
            continue;
        }
        if(a==c&&c==big){
            cout<<"1"<<" "<<big-b+1<<" "<<"1"<<endl;
            continue;
        }
        if(a==big)
            cout<<"0"<<" ";
        else
            cout<<big-a+1<<" ";
        if(b==big)
            cout<<"0"<<" ";
        else
            cout<<big-b+1<<" ";
        if(c==big)
            cout<<"0"<<endl;
        else
            cout<<big-c+1<<endl;
    }
    return 0;
}
