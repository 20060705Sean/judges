#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[2005][5];
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        bool right=0;
        int x=0;
        int y=0;
        int z=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++)
                cin>>a[i][j];
        }
        for(int i=0;i<5;i++){
            for(int j=i+1;j<5;j++){
                int k=0;
                x=0;
                y=0;
                z=0;
                for(int k=0;k<n;k++){
                    if(i!=j){
                        if(a[k][i]==1&&a[k][j]==1){
                            y++;
                        }
                        else if(a[k][i]==1){
                            x++;
                        }
                        else if(a[k][j]==1){
                            z++;
                        }
                    }
                }
                if(x+y+z==n&&x+y>=n/2&&z+y>=n/2){
                    right=1;
                    break;
                }
            }
            if(right==1)
                break;
        }
        if(right)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
