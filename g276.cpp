#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct boss{
    bool valid;
    int x, y, s, t;
} boss[505];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,m,k;
    ll boom[100][100];
    bool bang[100][100];
    cin>>n>>m>>k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            boom[i][j] = 0;
            bang[i][j] = false;
        }
    }
    for(ll i=0;i<k;i++){
        cin>>boss[i].x>>boss[i].y>>boss[i].s>>boss[i].t;
        boss[i].valid=true;
    }
    ll p=k;
    while(p){
        for(ll i=0;i<k;i++){
            if(boss[i].valid){
            boom[boss[i].x][boss[i].y]++;
            boss[i].x+=boss[i].s;
            boss[i].y+=boss[i].t;
            }
        }
        for(ll i=0;i<k;i++){
            if(boss[i].valid){
                if((boss[i].x<0||boss[i].x>=n)||(boss[i].y<0||boss[i].y>=m)){
                    boss[i].valid=false;
                    p--;
                }else if(boom[boss[i].x][boss[i].y]){
                    bang[boss[i].x][boss[i].y]=true;
                    boss[i].valid=false;
                    p--;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bang[i][j]) {
                    boom[i][j] = 0;
                    bang[i][j] = false;
                }
            }
        }
    }
    ll ans=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += (boom[i][j] > 0);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
//用bool比int快很多
