#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n) ;
    getchar() ;
    while(n--){
        int len = 0;char c;vector<char> str;
        while((c=getchar())!='\n')
            if(c != '.') str.push_back(c);
        int pairs=0, p=0 ;
        for(int i=0; i<str.size(); i++){
            if (str[i] == 'p') p++;
			else if (p) {p--;pairs++;}
        }
        printf("%d\n", pairs) ;
    }
    return 0 ;
}
