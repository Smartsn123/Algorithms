#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

bool prime[100000];
ull prime_stack[100000];
ull size;


ull times_div(ull a, ull b)
{ //cout<<"time_div"<<b<<endl;
  ull count=0;
  while(a%b==0 && a>1)
  {count++; a=a/b;}

  return count;
}

bool is_prime(ull a)
{
  ull limit=sqrt(a);
  ull i=0;
  bool flag=1;
  while(prime_stack[i]<limit)
  { if(a%prime_stack[i]==0)
     {flag=0;break;}
  }
  
  return flag;
   
}

void seive()
{ size=0;
  for(ull i=2;i<=100000;i++)
  { 
   if(prime[i]==0)
   {prime_stack[size++]=i;
   for(ull j=2;j*i<=100000;j++)
   prime[i*j]=1;
   }
  }
}


int main()
{  seive();
   prime_stack[0]=2;
  // for(int i=0;i<10;i++)
 //  {cout<<prime_stack[i]<<endl;}
   
  ull t;
  ull powera[100005]={0};
  ull powerb[100005]={0};
  scanf("%lld",&t);
  while(t--)
  {
   ull a,b,c,d;
   scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
   ull i=0;
  // cout<<"powera"<<endl;
   while(prime_stack[i]<=a)
   { 
     powera[i]=times_div(a,prime_stack[i])*b;
  //   cout<<prime_stack[i]<<" : "<<powera[i]<<"  ";
     i++;
   }
   // cout<<endl;
   //cout<<"powerb"<<endl;
   ull j=0;
   while(prime_stack[j]<=c)
   { 
     powerb[j]=times_div(c,prime_stack[j])*d;
   
    // cout<<prime_stack[j]<<":"<<powerb[j]<<"  ";
       j++;
   }
   //cout<<endl;

   if(is_prime(a) && is_prime(c) && a==c && b>d)
    printf("Divisible\n");
   else
   {   bool flag=1;
       for(ull k=0;k<j;k++)
         flag*=(powerb[k]<=powera[k]);
       if(flag)
       printf("Divisible\n");
       else
       printf("Not divisible\n");
   }
  }

return 0;
}
