#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

int main()
{
  ull t;
  scanf("%lld",&t);
  while(t--)
  {
    ull n,m;
    ull dist[100005];
    ull max_dist=0;
    ull sum=0;

    scanf("%lld",&n);
    for(ull i=1;i<=n;i++)
    {scanf("%lld",&dist[i]);
     max_dist+=dist[i];
    }
    //printf("max_dist  : %lld\n",max_dist);
    scanf("%lld",&m);
    
    sum+=max_dist*(m/max_dist);
    //printf("sum  : %lld\n",sum);

    ull i=1;
    while(sum<m)
      sum+=dist[i++];
    i--;

    if(m!=0 && i==0)
    printf("%lld\n",n);
    else
    printf("%lld\n",i);
   
  }
  
 return 0;

}
