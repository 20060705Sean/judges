#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string num;
        cin>>num;
        int length=num.size();
        int ans=0;
        for(int i=0;i<length;i++){
            if(num[length-i-1]=='0'){
                for(int j=i+1;j<length;j++){
                    if(num[length-j-1]=='5'||num[length-j-1]=='0'){
                        break;
                    }
                ans++;
                }
                break;
            }
            if(num[length-i-1]=='5'){
                for(int j=i+1;j<length;j++){
                    if(num[length-j-1]=='2'||num[length-j-1]=='7'){
                        break;
                    }
                    if(num[length-j-1]=='0'){
                        for(int k=j+1;k<length;k++){
                            if(num[length-k-1]=='5'||num[length-k-1]=='0'||num[length-k-1]=='2'||num[length-k-1]=='7'){
                                ans++;
                                break;
                            }
                        ans++;
                        }
                    break;
                    }
                ans++;
                }
                break;
            }
        ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
