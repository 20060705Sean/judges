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

int n,lis;
vector<int> g(500005,INF),a(500005);
vector<int>::iterator idx;

int main(){
    //WOW
    int len = 0;
    while(cin >> n){
        a[len] = n;
        len++;
    }
    vector<int> LIS(len);
    int can = 0;
    for(int i = 0 ; i < len ; i++){
        idx = lower_bound(g.begin(),g.end(),a[i]);
        *idx = a[i];
        int lis = (int)(idx - g.begin() + 1);
        LIS[i] = lis;
        if(can < lis) can = lis;
    }
    cout << can << "\n-\n";
    vector<int> ans;
    for(int i = len-1 ; i >= 0 ; i--){
        if(LIS[i] == can){
            ans.PB(a[i]);
            can--;
        }
        if(can < 0 ) break;
    }
    int Size = ans.size();
    for(int i = Size-1 ; i >= 0 ;i--){
        cout << ans[i];
        if(i != 00)
            cout << "\n";
    }
    return 0;
}
