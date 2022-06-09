#include <iostream>
using namespace std;
int main(){
    int h, l, r, build[10001]={0}, maxr = 0;
    while(cin>>l>>h>>r)
    {
        maxr = max(maxr, r);
        for(int index = l; index < r; ++index)
            build[index] = max(h, build[index]);
    }
    if(build[0])
        cout<<0<<" "<<build[0]<<" ";
    for(int i = 1; i < maxr + 2; ++i)
        if(build[i - 1] != build[i])
            cout<<i<<" "<< build[i]<<" ";
    cout<<endl;
    return 0;
}