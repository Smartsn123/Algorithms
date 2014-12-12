#include<bits/stdc++.h>
using namespace std;
#define ull int 


void Merge(ull a[100005],ull low1,ull high1,ull low2, ull high2)
{ //printf("into Merge\n");
  ull c[100005]; 
  ull i1=low1,i2=low2,j1=high1,j2=high2,i=low1;
 
  while(i1<=j1 && i2<=j2)
  { if(a[i1]<=a[i2])
    c[i++]=a[i1++];
    else 
    c[i++]=a[i2++];
  }
  
  while(i1<=j1)
  c[i++]=a[i1++];
  
  while(i2<=j2)
  c[i++]=a[i2++];

  while(low1<=high2)
  a[low1]=c[low1++];
  
}



void MergeSort(ull a[100005],ull low,ull high)
{  //printf("Merge Sort\n");
   if(low ==high)
    return ;
   ull mid=low+(high-low)/2;
   MergeSort(a,low,mid);
   MergeSort(a,mid+1,high);
   Merge(a,low,mid,mid+1,high);
}


int main()
{  ull n;
   scanf("%d",&n);
   ull a[100005];
   
   for(int i=0;i<n;i++)
   scanf("%d",a+i);
   // printf("Sucessful input\n");
   MergeSort(a,0,n-1);

   for(ull i=0;i<n;i++)
   printf("%d ",a[i]);
   printf("\n");
   return 0;
   
}
