#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int i,n,ans=0,l,r;
   cin>>n;
   char c[5];
   stack<int> S;

   for(i=0;i<n;i++)
   {
       cin>>c;
       if(c[0]!='+' && c[0]!='-' && c[0]!='*' && c[0]!='/')
       {
         S.push(atoi(c));
         //cout<<c[0]<<" ="<<i<<"   ";
       }
       else
       {
           r=S.top();
           S.pop();
           if(S.size()==0)
           {
               cout<<"INVALID";
               return 0;
           }
           l=S.top();
           S.pop();
           //cout<<l<<c<<r<<"\n";
           if(c[0]=='+')
            ans=l+r;
           else if(c[0]=='-')
                ans=l-r;
            else if(c[0]=='*')
            ans=l*r;
            else
            {
                if(l==0)
                   {
                       cout<<"INVALID";
                       return 0;
                   }
                ans=l/r;
            }
           // cout<<"-"<<ans<<"-";
            S.push(ans);
       }
   }
   ans=S.top();
   S.pop();
    if(S.size()!=0)
           {

               cout<<"INVALID";
               return 0;
           }
   cout<<ans;


return 0;
}
