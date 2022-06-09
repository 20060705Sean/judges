
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
int i,n,m,a[50005],apneed,l,r,ans;
    scanf("%d %d",&m,&n);
    for(i=0; i<m; i++) scanf("%d",&a[i]);
    sort(a,a+m);

    l=1;
    r=ans=(a[m-1]-a[0])/n+1;

    while(l<r) //binary search
    {
        int d=(l+r)/2;
        int now=a[0];
        for(i=apneed=1; i<m; i++)
        {
            if(a[i]>now+d)
            {
                apneed++;
                now=a[i];
            }
        }
        if(apneed<=n)
            ans=r=d;
        else
            l=d+1;
    }
    printf("%d\n",ans);

	return 0;
}