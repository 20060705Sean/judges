#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int a[3];
    while(t){
        for(int i=0;i<3;i++)
            cin>>a[i];
        sort(a,a+3);
        int ans=a[0]+a[2]-2*a[1];
        if(ans%3) cout<<"1"<<endl;
        else cout<<"0"<<endl;
        t--;
    }
    return 0;
}
