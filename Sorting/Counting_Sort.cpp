#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void counting_sort(int *arr,int *ans,int k,int n)
{
    int i,tmp[100001]={0};
    for(i=0;i<n;i++)
            tmp[arr[i]]++;
    for(i=1;i<=k;i++)
        tmp[i]+= tmp[i-1];
    for(i=k;i>=0;i--)
        {
            ans[tmp[arr[i]]]=arr[i];
            tmp[arr[i]]--;
        }
}
int main()
{
  int n;
 //cout<<"No. of elements: ";
 cin>>n;
 int i,arr[100001];
 //cout<<"Enter the elements: ";
 int k=0;
 for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>k)
                k=arr[i];
        }
 int sorted[100001]={0};

 counting_sort(arr,sorted,k,n);

 for(i=1;i<=n;i++)
        cout<<sorted[i]<<" ";

return 0;
}
