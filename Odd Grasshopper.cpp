#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long a1;
    long long jp;
    cin>>t;
    //result is 4 in a cycle
    while(t){
        cin>>a1>>jp;
        int m=jp%4;
        for(long long i=jp+1-m;i<=jp;i++){
            if(a1%2)
                a1+=i;
            else a1-=i;
        }
        cout<<a1<<endl;
        t--;
    }

    return 0;
}
