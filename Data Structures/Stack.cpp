#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Stack
{
    private:
        int top;
        int *S;
        int size;
    public:
       Stack(int size)
       {
           S= new int[size];
           this->size=size;
           top=0;
       }
       void push(int x)
        {
            S[top] = x;
            top++;
        }
        void pop()
        {
            if(top==0)
                cout<<"Stack underflow!\n";
            else
                {
                    top--;
                    cout<<"popped :"<<S[top]<<endl;
                }
        }
        void display()
        {
            for(int i=0;i<top;i++)
                cout<<S[i]<<" ";
            cout<<endl;
        }
        ~Stack()
        {
            delete S;
            cout<<"Stack destroyed\n";
        }
};
int main()
{
    Stack S(100);
    int t=1,n=1,x;
    while(n>0){
    cout<<"0 to exit; 1 to push; 2 to pop; 3 to print stack : ";
    cin>>n;
    if(n==1)
       {
           cout<<"Enter the element to push: ";
           cin>>x;
           S.push(x);
       }
    else if(n==2)
           S.pop();

    else if(n==3)
       S.display();

    else if(n!=0)
        cout<<"Invalid option\n";

    }

return 0;
}
