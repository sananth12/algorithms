#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* Largest Contigious Subarray sum*/
int LCS(int *arr,int n)
{
    int i,max_so_far=arr[0],curr_max=arr[0];
    for(i=1;i<n;i++)
    {
        curr_max= max( arr[i], curr_max+arr[i]);
        max_so_far = max( max_so_far,curr_max);
    }
    return max_so_far;
}

int main()
{
   int n;
   cin>>n;
   int arr[n],i;
   for(i=0;i<n;i++)
    cin>>arr[i];

    cout<<"Maximum sum = "<<LCS(arr,n);

return 0;
}
