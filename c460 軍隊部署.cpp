#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define WOW ios::sync_with_stdio(false);cin.tie(0);
#define PB push_back
#define F first
#define S second
#define INF 2147483647
#define LINF 4294967295
#define Mod 10e9+7
//#pragma GCC optimize("O3")

int fst[8], sed[8],trd[8],n,c,a,r,d;
ll dp12[8],dp123[8];

int record(int x, int y, int z){
    int ret = 0;
    if(x)
        ret |= 1;
    if(y)
        ret |= (1<<1);
    if(z)
        ret |= (1<<2);
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> c >> a >> r >> d;
        if(c == 1)
            fst[record(a,r,d)] ++ ;
        if(c == 2)
            sed[record(a,r,d)] ++ ;
        if(c == 3)
            trd[record(a,r,d)] ++ ;
    }

    for(int i = 0 ; i < 8 ; i++)
        for(int j = 0 ; j < 8 ; j++)
            dp12[i|j] += fst[i]*sed[j];

    for(int i = 0 ; i < 8 ; i++)
        for(int j = 0 ; j < 8 ; j++)
            dp123[i|j] += trd[i]*dp12[j];

    cout << dp123[7] << "\n";
    return 0;
}
