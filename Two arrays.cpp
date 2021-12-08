#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[100];
        int b[100];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(b,b+n);
        bool yn=true;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]&&a[i]+1!=b[i])
                yn=false;
        }
        if(yn)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
