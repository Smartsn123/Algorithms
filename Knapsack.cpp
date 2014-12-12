#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

ull Knapsack(ull size[], ull wt[],ull n,ull S)
{
  ull KnapSack[n+1][S+1];
  
  for(int i=0;i<=S;i++)
  { KnapSack[0][i]=0;
    KnapSack[i][0]=0;
  }
  
  for(int j=1;j<=S;j++)
   {
     for(int i=1;i<=n;i++)
     {
         KnapSack[i][j]=KnapSack[i-1][j];
         if(size[i]<=j)
          KnapSack[i][j]= max(KnapSack[i][j],KnapSack[i-1][j-size[i]] + wt[i]) ;
     }
   }

  return KnapSack[n][S];
}


int main()
{ 
  ull S,n;
  ull size[2002];
  ull wt[2002];
  scanf("%lld %lld",&S,&n);
  
  for(int i=1;i<=n;i++)
  scanf("%lld %lld",&size[i],&wt[i]);

  printf("%lld\n",Knapsack(size,wt,n,S));
  return 0;
}
