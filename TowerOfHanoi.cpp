#include<bits/stdc++.h>
using namespace std;


int steps(int n_disks,int src,int temp,int dest)
{
  // base case
   if(n_disks==1)
   return 1;
  
  //the recursive sol is to count recursively the no of steps to move disks 1 to n-1 to the temp , 
  //add 1 to move last disc to destination , 
  //and recursively count no of steps to move those n-1 , discs to destination from temp , using src

   return   steps(n_disks-1,src,dest,temp)+1+steps(n_disks-1,temp,src,dest);  

}


int main()
{
   int t;
   printf("Enter the no of test cases\n");
   scanf("%d",&t);
   while(t--)
   {
     int n;
     printf("Enter the no of pegs to be moved\n");
     scanf("%d",&n);
    
     printf("Optimal no of steps to move the Discs to Destination Peg are: %d , Real count %d\n",steps(n,0,1,2),int(pow(double(2),n))-1) ;  
      
   }
  return 0;
}
