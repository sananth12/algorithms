#include<iostream>
#include<stdio.h>
#define maxi(x,y) (x>y)?x:y;
#define N 2000001
int v[501],w[501];
int s[N],t[N];
using namespace std;

int main()
{
    int i,k,n,j;
    cin>>k>>n;

    for(i=1;i<=n;i++)
        scanf("%d%d",&(v[i]),&(w[i]));

    for(i=0;i<=k;i++)
    {
        t[i]=0;
        s[i]=0;
    }

    for(i=1;i<=n;i++)
    {
        if(i%2)
        {
                for(j=1;j<=k;j++)
                {
                        if(w[i]<=j){
                            t[j] = maxi(s[j],s[j-w[i]]+v[i]);}
                        else{
                            t[j] = s[j];}

                }
        }
        else
        {
                for(j=0;j<=k;j++)
                {
                        if(w[i]<=j){
                            s[j] = maxi(t[j],t[j-w[i]]+v[i]);}
                        else{
                            s[j] = t[j];}

                }
        }
    }

    if(n&1)
        printf("%d",t[k]);
    else
        printf("%d",s[k]);

    return 0;
}
