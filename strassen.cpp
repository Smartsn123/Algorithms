//Strasen's Divide and conquer approach to multipy two matrices 

#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define loop(i,n,k) for(ull i=k;i<=n;i++)
#define mat(m) ull m[][]


void copy(ull a[][],ull b[][],ai,aj,n,m)
{
  loop(i,n,ai)
   { loop(j,m,aj)
      b[i][j]=a[i][j];
   }
}

void sub(ull a[][],ull b[][],n,m,res[][])
{
  loop(i,n,ai)
   { loop(j,m,aj)
      res[i][j]=a[i][j]-b[i][j;
   }
}

void sum(ull a[][],ull b[][],n,m,res[][])
{
  loop(i,n,ai)
   { loop(j,m,aj)
      res[i][j]=a[i][j]+b[i][j;
   }
}

void multi(mat(m),mat(n),mat(res), ull begi1,ull begj1,ull n1,ull m1,ull begi2, ull begj2,ull n2, ull m2)
{
   ull midx1=begi1+(n1-begi1)/2;
   ull midy1=begj1+(m1-begj1)/2;
   ull midx2=begi2+(n2-begi2)/2;
   ull midy2=begj2+(n2-begj2)/2;
   
   ull a[midx1+1][midy1+1]; //a
   ull b[midx1+1][midy1+1]; //b
   ull c[midx1+1][midy1+1]; //c
   ull d[midx1+1][midy1+1]; //d
   ull e[midx1+1][midy1+1]; //e
   ull f[midx1+1][midy1+1]; //f
   ull g[midx1+1][midy1+1]; //g
   ull h[midx1+1][midy1+1]; //h
  
  //copying parts of m into a,b,c,d
   copy(m,a,begi1,begj1,midx1,midy1);
   copy(m,b,begi1,midy1+1,midx1,m1);
   copy(m,c,midx1+1,begj1,n1,midy1);
   copy(m,d,midx1+1,midy1+1,n1,m1);

  //cpoying parts of n into e,f,g,h
   copy(n,e,begi2,begj2,midx2,midy2);
   copy(n,f,begi2,midy2+1,midx2,m2);
   copy(n,g,midx2+1,begj2,n2,midy2);
   copy(n,h,midx2+1,midy2+1,n2,m2);
 
  
   ull p1[midx1+1][midy1+1];
   ull d1[midx1+1][midy1+1];
   sub(f,midx2,midy2,h,midx2,midy2,d1);
   multi(a, d1,p1, 0,0,midx1,midy1,0, 0,midx2, midy2);
   
   ull p2[midx1+1][midy1+1];
   ull s2[midx1+1][midy1+1];
   sum(a,midx2,midy2,b,midx2,midy2,s2);
   multi(s2,h,p2, 0,0,midx1,midy1,0, 0,midx2, midy2);

   ull p3[midx1+1][midy1+1];
   ull s3[midx1+1][midy1+1];
   sum(c,midx2,midy2,d,midx2,midy2,s3);
   multi(s3,e,p3, 0,0,midx1,midy1,0, 0,midx2, midy2);

   
   ull p4[midx1+1][midy1+1];
   ull d4[midx1+1][midy1+1];
   sub(g,midx2,midy2,e,midx2,midy2,d4);
   multi(g, d4,p4, 0,0,midx1,midy1,0, 0,midx2, midy2);
  
   ull p5[midx1+1][midy1+1];
   ull s51[midx1+1][midy1+1];
   sum(a,midx2,midy2,d,midx2,midy2,s51);
   ull s52[midx1+1][midy1+1];
   sum(e,midx2,midy2,h,midx2,midy2,s52);
   multi(s51,s52,p5, 0,0,midx1,midy1,0, 0,midx2, midy2);

   ull p6[midx1+1][midy1+1];
   ull s61[midx1+1][midy1+1];
   sub(b,midx2,midy2,d,midx2,midy2,s61);
   ull s62[midx1+1][midy1+1];
   sum(g,midx2,midy2,h,midx2,midy2,s62);
   multi(s61,s62,p6, 0,0,midx1,midy1,0, 0,midx2, midy2);

    
   ull p7[midx1+1][midy1+1];
   ull s71[midx1+1][midy1+1];
   sub(a,midx2,midy2,c,midx2,midy2,s71);
   ull s72[midx1+1][midy1+1];
   sum(e,midx2,midy2,f,midx2,midy2,s72);
   multi(s71,s72,p7, 0,0,midx1,midy1,0, 0,midx2, midy2);
 
   
}


int main()
{
  ull a[1024][1024]={0};
  ull b[1024][1024]={0};
  
  cout<<"Enter matrix 1: \n";
  
   
 
 return 0;  
}
