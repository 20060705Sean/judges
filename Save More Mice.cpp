#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[k];
        for(int i=0;i<k;i++)
            cin>>a[i];
        if(k==1){
            cout<<"1"<<endl;
            continue;
        }
        sort(a,a+k);
        int cat=0;
        int lived=0;
        for(int i=k-1;i>=0;i--){
            if(cat>=a[i])
                break;
            lived++;
            int moved=n-a[i];
            cat+=moved;
        }
        cout<<lived<<endl;
    }
    return 0;
}
