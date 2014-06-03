#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void push(int *S,int x,int &top)
{
    S[top] = x;
    top++;
}
void pop(int *S,int &top)
{
    if(top==0)
        cout<<"Stack underflow!";
    else
        {
            top--;
            cout<<"popped :"<<S[top]<<endl;
        }
}
int main()
{
    int i,n,x,t=1;
    int *S,top=0;
    while(t==1){
    cout<<"1 to push,2 to pop,3 to print stack : ";
    cin>>n;
    if(n==1)
       {
           cout<<"Enter the element to push: ";
           cin>>x;
           push(S,x,top);
       }
    else if(n==2)
    {
           pop(S,top);
    }
    else if(n==3)
    {
        for(i=0;i<top;i++)
            cout<<S[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"Invalid option\n";

    cout<<"Enter 1 to continue,0 to exit: ";
    cin>>t;
    }
return 0;
}
