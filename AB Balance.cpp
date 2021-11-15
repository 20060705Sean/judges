#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    string a;
    while(t){
        cin>>a;
        if(a[a.length()-1]==a[0]){}
        else if(a[0]=='a')
            a[0]='b';
        else
            a[0]='a';
        cout<<a<<endl;
        t--;
    }
    return 0;
}
