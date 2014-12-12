#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int


ull SplitInvCount(ull a[100005],ull low1,ull high1,ull low2,ull high2)
{// printf("computing Inv count on %lld to %lld :\n",low1,high2);
  ull count=0, c[100005];
  ull i1=low1,j1=high1,i2=low2,j2=high2;

 //for(ull i=low1;i<=high2;i++)
 // printf("%lld ",a[i]);
  // printf("\n");

  ull i=low1;
  while(i1<=j1 && i2<=j2)
  {
    if(a[i1]<=a[i2])
     c[i++]=a[i1++];
    else 
    { c[i++]=a[i2++]; count+=high1-i1+1;}
  }

  while(i1<=j1)
  c[i++]=a[i1++];
  
  while(i2<=j2)
  c[i++]=a[i2++];

  ull j=low1;
  while(low1<=high2)
  a[low1]=c[low1++];
// printf("%lld\n",count);

 //  for(ull i=j;i<=high2;i++)
 //  printf("%lld ",c[i]);
 // printf("\n");

  return count;
}


ull InvCount(ull a[100005], ull low , ull high)
{ 
  if(low==high)
  return 0;  

  ull  right_inv_count=0;
  ull left_inv_count=0;
  ull split_inv_count=0;
  ull mid=low+(high-low)/2;
  
  right_inv_count=InvCount(a,low,mid);
  left_inv_count=InvCount(a,mid+1,high);
  split_inv_count=SplitInvCount(a,low,mid,mid+1,high);

  return right_inv_count + left_inv_count + split_inv_count ;

}

int main()
{  
 
   ull n,k;
   scanf("%lld %lld",&n,&k);
 
   ull a[100005];
   

   for(int i=0;i<n;i++)
   { 
     scanf("%lld",&a[i]);
       }

   
   printf("%lld\n",InvCount(a,0,n-1));

 // for(ull i=0;i<n;i++)
   //printf("%lld ",a[i]);
  // printf("\n");
  // scanf("%lld",&n);
  }
   return 0;
   
}
