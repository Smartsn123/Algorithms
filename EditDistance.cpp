#include<bits/stdc++.h>
using namespace std;
char in1[100005];
char in2[100005];
int D,I,R;

int EditDist(char * a,char * b)
{
  int l1=strlen(a);
  int l2=strlen(b);
  
  int dp[l1+2][l2+2];
  
  for(int i=0;i<=l1;i++)
  {dp[i][0]=i;}
  for(int i=0;i<=l2;i++)
  {dp[0][i]=i;}

  for(int i=1;i<=l1;i++)
  { for(int j=1;j<=l2;j++)
     {
        dp[i][j]=min(dp[i-1][j]+D,dp[i][j-1]+I);
        if(a[i-1]!=b[j-1])
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+R);
        else
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
        printf("%d  ",dp[i][j]);
     }
    printf("\n");
  }

  return dp[l1][l2];
  
}

int main()
{
  
  scanf("%d %d %d",&D,&I,&R);
  scanf("%s",in1);
  scanf("%s",in2);
  int ans=0;
  ans= EditDist(in1,in2);
  
  printf("Minimum Edit Distance : %d\n",ans);
  return 0;
}
