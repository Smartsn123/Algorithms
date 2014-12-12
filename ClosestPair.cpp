#include<bits/stdc++.h>
using namespace std;
#define unsigned long long int
#define max 1000000000
ull x1,y1,x2,y2;

void closestPair(ull x[],ull y[],ull beg,ull end, ull res[])
{
  if(beg==end)
   { res[0]=max;res[1]=    
    return ;}
  
  ull mid=low+(high-low)/2;
  ull res1[6],res2[6];
  cloasestPair(x,y,beg,mid,res1);
  closestPair(x,y,mid+1,end,res2);
  
  CrossMin(x,y,beg,mid,mid+1,end,res); 
  
}



int main()
{
  ull n;
  scanf("%lld",&n);
  ull x[10005];
  ull y[10005];
  
  for(int i=0;i<n;i++)
  scanf("%lld %lld",&x[i],&y[i]);
  
  
  


  
  
}
