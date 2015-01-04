/*
    1 2 3
    4 5 6
    7 8 9
    \
     \
      \
    min cost path = 1 + 5 + 9 = 15
*/
#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define R 300
#define C 300
ll MCP(ll G[R][C],ll n, ll m)
{
    ll i,j,dp[n][m];
     dp[0][0]=G[0][0];
     for (i= 1; i<n; i++)
        dp[i][0] = dp[i-1][0] + G[i][0];

     for (j=1;j<m;j++)
        dp[0][j] = dp[0][j-1] + G[0][j];

     for(i=1;i<n;i++)
        for(j=1;j<m;j++)
            dp[i][j] = std::min( dp[i-1][j] , std::min( dp[i][j-i] , dp[i-1][j-1])) + G[i][j];

    return dp[n-1][m-1];
}
using namespace std;
int main()
{
   ll n,m,i,j;
   cin>>n>>m;
   ll G[R][C];

   for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>G[i][j];

   cout<<MCP(G,n,m);

return 0;
}
