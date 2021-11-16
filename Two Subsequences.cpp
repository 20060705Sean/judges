#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string a;
    int pl;
    cin>>t;
    while(t--){
        cin>>a;
        char f1='z'+1;
        for(int i=0;i<a.length();i++){
            if(a[i]<f1){
                f1=a[i];
                pl=i;
            }
        }
        cout<<f1<<" ";
        for(int i=0;i<pl;i++)
            cout<<a[i];
        for(int i=pl+1;i<a.length();i++)
            cout<<a[i];
        cout<<endl;
    }
    return 0;
}
