//Spoj Problem NHAY
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int



void KMP_lps(ull lps[] ,char *pat,ull M)
{
  ull len=0;
  lps[0]=0;
  ull i=1;
   
  while(i<M)
  {
    if(pat[i]==pat[len])
     {len++; 
      lps[i]=len;
      i++;
     }
    else if(len!=0)
     len=lps[len-1];
    else
     {lps[i]=0;
      i++;
     }
   }
}



void KMPsearch(char *pat,char *txt)
{ 
  ull N=strlen(txt);
  ull M=strlen(pat);
  ull lps[M+1];
  KMP_lps(lps,pat,M);
  ull j=0;//counter for pat
  ull i=0;//counter for txt
  bool flag=1;
  while(i<N)
  { 
    if(txt[i]==pat[j])  // keep moving ahead until the patern and the text matches
     {i++;j++;}
    
    if(j==M)            // the case when pattern is found   
    { printf("%lld\n",(i-j));
      j=lps[j-1];flag=0;
     }
    else if(pat[j]!=txt[i])  // when some part of the pattern  is found
    {
       if(j!=0)   
         j=lps[j-1];
       else   // case when even not single character of pattern has not been found
         i+=1;
    }
   }
  if(flag)
  printf("\n");
}




int main()
{
  ull M;

  while(scanf("%lld",&M)!=EOF)
  {
  char lps[1000006];
  char pat[1000006];
  char txt[1000006];
  
  scanf("%s",pat);
  scanf("%s",txt);
  KMPsearch(pat,txt);
  
  }
  return 0;
}

