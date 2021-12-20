#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int x, y;
    bool x_odd, y_odd;
    while(t--){
        cin >> x >> y;
        x_odd = (x & 1);
        y_odd = (y & 1);
        if(x_odd && y_odd){
            cout << (x + 1) / 2 << ' ' << (y - 1) / 2 << "\n";
        } else if (!x_odd && !y_odd){
            cout << x / 2 << " " << y / 2 << "\n";
        } else {
            cout << -1 << " " << -1 << "\n";
        }
    }
}

