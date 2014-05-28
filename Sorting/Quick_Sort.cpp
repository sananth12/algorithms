#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int partition(int *arr,int l,int r)
{
    int key=arr[r],x=l;
    for(int i=l;i<r;i++)
    {
       if(arr[i]<=key)
            {
                swap(arr[x],arr[i]);
                x++;
            }
    }
    swap(arr[x],arr[r]);
    return x;
}
void quick_sort(int *arr,int l,int r)
{
    if(l<r)
    {
        int mid=partition(arr,l,r);
       // cout<<"*"<<mid<<"*";
        quick_sort(arr,l,mid-1);
        quick_sort(arr,mid+1,r);
    }
}
using namespace std;
int main()
{
    int n;
    cout<<"No. of elements: ";
    cin>>n;
    int i,arr[n];
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    quick_sort(arr,0,n-1);
     for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
return 0;
}
