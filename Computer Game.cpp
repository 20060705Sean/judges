#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n;
    string a;
    string b;
    while(t--){
        cin>>n;
        cin>>a>>b;
        bool right=1;
        for(int i=0;i<n;i++){
            if(a[i]=='1'&&b[i]=='1'){
                right=0;
                break;
            }
        }
        if(right)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
