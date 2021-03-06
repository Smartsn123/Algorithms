#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
#define ull  int
#define mat(x) x[300][300]

void disp(ull mat(x),ull i,ull j , ull m, ull n)
{
  for(int k=i;k<=m;k++)
  { for(int l=j;l<=n;l++)
     printf("%d  ",x[k][l]);
     printf("\n");
   }
  printf("\n");
  printf("\n");
}

void copy(ull mat(A),ull mat(C),ull i,ull j , ull m, ull n)
{
  for(int k=i;k<=m;k++)
  { for(int l=j;l<=n;l++)
      C[k][l]=A[k][l];
   }
}


void str_multi(ull mat(A),ull ai,ull aj,ull am,ull an,ull mat(B),ull bi,ull bj , ull bm, ull bn, ull mat(res))
{
   //dividing matrix a into a,b,c,d 
   ull a1=ai+(am-ai)/2;
   ull a2=aj+(an-aj)/2;

   ull mat(a); copy(A,a,0,0,a1,a2);            printf("Matrix a:\n"); disp(a,0,0,a1,a2);
   ull mat(b); copy(A,b,0,a2+1,a1,an);         printf("Matrix b:\n");                    disp(b,0,a2+1,a1,an);
   ull mat(c); copy(A,c,a1+1,0,am,a2);         printf("Matrix c:\n");disp(c,a1+1,0,am,a2);
   ull mat(d); copy(A,d,a1+1,a2+1,am,an);      printf("Matrix d:\n");disp(d,a1+1,a2+1,am,an);


   //dividing matrix b into e,f,g,h 
   ull b1=bi+(bm-bi)/2;
   ull b2=bj+(bn-bj)/2;

   ull mat(e); copy(B,e,0,0,b1,b2);            printf("Matrix e:\n");disp(e,0,0,b1,b2);
   ull mat(f); copy(B,f,0,b2+1,b1,bn);         printf("Matrix f:\n"); disp(f,0,b2+1,b1,bn);
   ull mat(g); copy(B,g,b1+1,0,bm,b2);         printf("Matrix g:\n");disp(g,b1+1,0,bm,b2);
   ull mat(h); copy(B,h,b1+1,b2+1,bm,bn);      printf("Matrix h:\n"); disp(h,b1+1,b2+1,bm,bn);
   
   
   ull mat(f1); sub(f,0,b2+1,b1,bn,h,b1+1,b2+1,bm,bn,f1);
   str_multi(a,0,0,a1,a2,);
   
}



int main()
{
  ull m1,n1,m2,n2;
  ull mat(A),mat(B);
  printf("Enter the size of the First Matrix :\n");
  scanf("%d %d",&m1,&n1);
  printf("Enter the size of the Second Matrix :\n");
  

  scanf("%d %d",&m2,&n2);
  for(int i=0;i<m1;i++)
  { for(int j=0;j<n1;j++)
     A[i][j]=0+ rand() % 10;
   }
  printf("Matrix A:\n");
  disp(A,0,0,m1-1,n1-1);
  

  for(int i=0;i<m2;i++)
  { for(int j=0;j<n2;j++)
     B[i][j]=0+ rand() % 10;
   }
  printf("Matrix B:\n");
  disp(B,0,0,m2-1,n2-1);
  ull mat(res);
  str_multi(A,0,0,m1-1,n1-1,B,0,0,m2-1, n2-1,res);

 return 0;
}
