#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
   int s,n;
   cin>>s>>n;
   int dp[100][100]={0};
   int i,item[n][2];  // weight,value
   for(i=1;i<=n;i++)
       cin>>item[i][0]>>item[i][1];
   for(i=1;i<=n;i++)
        dp[i][0]=0;
   for(i=1;i<=n;i++)
   {
       for(int j=0;j<=s;j++)
       {
           if(item[i][0]<=j)
            dp[i][j]=max( dp[i-1][j], dp[i-1][j-item[i][0]]+ item[i][1] );
            else
            dp[i][j]=dp[i-1][j];

          //  cout<<dp[i][j]<<" ";
       }
      // cout<<endl;
   }
    cout<<dp[n-1][s];
return 0;
}
