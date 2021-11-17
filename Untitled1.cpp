#include<bits/stdc++.h>
using namespace std;
string st;
int correct();
 int main()
 {
    int num,i,j,cor=0;

    while(cin >> num && num<=pow(10,5)){

        for(i=1;i<=num;i++)
        {
            cin >> st;
            cor=cor+correct();
            cout << cor;

        }
        cout << cor;

    }

    return 0;
 }
int correct()
{
    int a=0,cor=0,j,t;
    for(j=0;j<(st.length()-1)/2;j++)
    {
        if(cor>=2)
        {
            a=0;
            break;
        }
        else
        {
            if(st[j]!=st[st.length()-j-1])
            {
                cor++;
            }

        }

        a=1;
    }
    return a;
}
