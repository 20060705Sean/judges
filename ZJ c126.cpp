#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#define WOW ios::sync_with_stdio(false);cin.tie(0);
#define EB emplace_back
#define F first
#define S second

string pre, in;

void findthetree(int Pre, int In, int len){
    if(In == len) {
        return;
    }
    int rootidx = 0;
    for(; rootidx <= len; ++rootidx){
        if(in[rootidx] == pre[Pre])
            break;
    }
    findthetree(Pre + 1,In, rootidx);
    findthetree(Pre + (rootidx - In + 1), rootidx + 1 , len);
    cout << pre[Pre];
    return;
}

int main(){
    WOW
    while(cin >> pre >> in){
        findthetree(0,0,pre.size());
        cout << "\n";
    }
    return 0;
}
