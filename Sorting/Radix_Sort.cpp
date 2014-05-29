#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void counting_sort(int *arr,int n,int exp)
{
    int i,tmp[100001]={0},ans[100001]={0};
    for(i=0;i<n;i++)
            tmp[ (arr[i]/exp)%10 ]++;
    for(i=0;i<10;i++)
        tmp[i]+= tmp[i-1];
    for(i=n-1;i>=0;i--)
        {
            ans[tmp[(arr[i]/exp)%10]-1]=arr[i];
            tmp[(arr[i]/exp)%10]--;
        }
     for (i=0;i<=n;i++)
        {
            arr[i] = ans[i];
        }
}
void radixsort(int *arr, int n)
{
    int max= *max_element(arr,arr+n);
    for (int exp=1; max/exp>0; exp*=10)
        counting_sort(arr, n, exp);
}

int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    //cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    radixsort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
