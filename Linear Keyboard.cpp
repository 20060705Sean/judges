#include<bits/stdc++.h>
using namespace std;

int main(){
    char a[26];
    string l;
    int t;
    cin>>t;
    while(t){
        for(int i=0;i<26;i++)
            cin>>a[i];
        cin>>l;
        int k1,k2;
        int lans,ans;
        ans=0;
        for(int i=1;i<l.length();i++){
            int x=0;
            while(a[x]!=l[i-1])
                x++;
            k1=x;
            x=0;
            while(a[x]!=l[i])
                x++;
            k2=x;
            lans=abs(k1-k2);
            ans+=lans;
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}
