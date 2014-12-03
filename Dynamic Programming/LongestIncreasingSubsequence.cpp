#include<bits/stdc++.h>
#define ll long long
using namespace std;

int LIS(int arr[],int n)
{
    if(n==1)
        return 1;

    int ans=1,i,j,dp[n+1];
    for(i=0;i<n;i++)
    	dp[i]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
            if( arr[i]>arr[j] && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j]+1;
                    ans= max(ans,dp[i]);
                   // cout<<ans<<" "<<i<<endl;
                }
    }
    return ans;
}
int main()
{
   int n;
   cin>>n;
   int i,a[n];
   for(i=0;i<n;i++)
        cin>>a[i];
    cout<<LIS(a,n);
return 0;
}
