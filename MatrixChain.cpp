//Sunny Singh IPG2012086 - Optimal Matrix chain Multiplication Recurssion Vs DP
#include<bits/stdc++.h>
using namespace std;
#define ull long long int
#define max 1000000000
ull p[1000];
ull cost[1000][1000];
ull br[1000][1000];
ull L[1000];
ull R[1000];

//-----------------------------------------------------------------------------------------------------------------------------------------------
//Optimal Matrix Chain Multiplication  using Recurssion
ull MatrixChainRec(ull i , ull j)
{
  // base case
   if(i==j)
   {cost[i][j]=0;return 0;}

   ull minv=max;
   ull count=0;
   br[i][j]=i+1;
  //place first bracket at i and last bracket at different positions and compute the no complexity for each case and select minimum one 
  for(ull k=i;k<j;k++)
  { 
    count=MatrixChainRec(i,k)+
         MatrixChainRec(k+1,j)+
         p[i-1]*p[k]*p[j];

   if(count<minv)
   {minv=count;br[i][j]=k;}
   
  }   
 cost[i][j]=minv;
 return minv;

 } 

//------------------------------------------------------------------------------------------------------------------------------------------------
//Optimal Matrix chain Multipliacation usinf Dynamic Programming
ull MatrixChainDp(int size)
{   printf("Enter DP\n");
   // initialize the cost matrix diagonal  for i==j as 0
    for(ull i=1;i<=size;i++)
       cost[i][i]=0;
    
    
    for(ull i=1;i<size;i++)//loop  corresponding to filling parallel to diagonal 
    {
       for(ull j=1;(j+i)<=size;j++)//loop to move through present diagonal
       { cost[j][j+i]=max;
         br[j][j+i]=j;
         for(ull k=j;k<=(j+i);k++)// loop to find minimum coast for the given range (j,j+i)
         {
           ull new_cost= cost[j][k]+ 
                         cost[k+1][j+i]+
                         p[j-1]*p[k]*p[j+i];
           

           if(new_cost < cost[j][j+i])
           { cost[j][j+i]=new_cost;
             br[j][j+i]=k;                  
            }
         }
       }
    }

   return cost[1][size];
}
//------------------------------------------------------------------------------------------------------------------------------------------------
// function to print Matrix with Position of Brackets for optimal Solution

void Parenthesis(ull i,ull j)
{
  if(i==j)
  printf("M%lld ",i);
  else
  {
    printf("(");
    Parenthesis(i,br[i][j]);
    Parenthesis(br[i][j]+1,j);
    printf(")");
    
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
  ull n;
 
  printf("Enter the No of Matrices\n");
  scanf("%lld",&n);
  printf("Enter the Matrix Chain\n");
  for(ull i=0;i<=n;i++)
  scanf("%lld",&p[i]);
  ull flag=0;
  printf("Choose the Method 1.Recurssion 2.DP\n");
  scanf("%lld",&flag);
   if(flag==1)
   {  printf("Min Cost : %lld\n",MatrixChainRec(1, n));
      Parenthesis(1,n);
    }
   else
   {printf("Min Cost : %lld\n",MatrixChainDp(n));
    Parenthesis(1,n);
    }

  printf("\n");
  return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
