#include<stdio.h>
#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;
int heap_size,length;
void max_heapify(int *arr,int x)
{
    int left=x*2;
    int right=x*2 +1;
    int max=x;
    if(arr[left]>arr[x] && left<=heap_size )
        max=left;
    if(arr[right]>arr[max] && right<=heap_size)
        max=right;
    if(max!=x)
        {
            swap(arr[x],arr[max]);
            max_heapify(arr,max);
        }
}
void build_max_heap(int *arr)
{
    heap_size = length;
    for(int i=heap_size/2;i>0;i--)
        max_heapify(arr,i);
}
void heapsort(int *arr)
{
    build_max_heap(arr);
    for(int i=length;i>=1;i--)
    {
        swap(arr[1],arr[i]);
        heap_size--;
        max_heapify(arr,1);
    }
}
int main()
{
    int n;
//    cout<<"No. of elements: ";
    cin>>n;
    int i,arr[100001];
  //  cout<<"Enter the elements: ";
    for(i=1;i<=n;i++)
        cin>>arr[i];

    length=n;
    heap_size=n;

    clock_t begin, end;
    double time_spent;
    begin = clock();

    heapsort(arr);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    for(i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<"\ntime_spent: "<<time_spent;

return 0;
}
