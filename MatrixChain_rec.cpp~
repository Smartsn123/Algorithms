#include<bits/stdc++.h>
using namespace std;
#define unsigned long long int

ull MatrixChainOrder(ull p[],ull i , ull j)
{
  // base case
   if(i==j)
   return 0;
   ull min=INT_MAX;
   ull cost=0;
  //place first bracket at i and last bracket at different positions and compute the no complexity for each case and select minimum one 
  for(int k=i;k<j,k++)
  { 
    cost=MatrixChainOrder(p,i,k)+
         MatrixChainOrder(p,k+1,j)+
         p[i-1]*p[k]*p[j];

   if(count<min)
   min=count;
   
  }   

 return min;

 } 

int main()
{
  ull t;
  scanf("%lld",&t);
  while(t--)
  {
    ull n,p[100005];
    scanf("%lld",&n);
    
    for(int i=0;i<n;i++)
    scanf("%lld",p[i]);

    printf("Optimatl complexity : %lld\n",MatrixChainOrder(p,0,n));
  }
 return 0;
}
  

