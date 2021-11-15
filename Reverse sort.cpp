#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string a;
    int n;
    cin>>t;
    int b[1005];
    while(t--){
        cin>>n;
        cin>>a;
        string an=a;
        sort(a.begin(),a.end());
        if(a==an)
            cout<<"0"<<endl;
        else{
            cout<<"1"<<endl;
            int j=0;
            for(int i=0;i<n;i++){
                if(a[i]!=an[i]){
                    b[j]=i+1;
                    j++;
                }
            }
            cout<<j<<" ";
            for(int i=0;i<j;i++){
                cout<<b[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
