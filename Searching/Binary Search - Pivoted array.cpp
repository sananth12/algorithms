#include <bits/stdc++.h>
using namespace std;
int findPivot(int[], int, int);
int binarySearch(int[], int, int, int);

int pivotedBinarySearch(int arr[], int arr_size, int no)
{
   int pivot = findPivot(arr, 0, arr_size-1);


   if (pivot == -1)
     return binarySearch(arr, 0, arr_size-1, no);


   if (arr[pivot] == no)
     return pivot;
   if (arr[0] <= no)
     return binarySearch(arr, 0, pivot-1, no);
   else
     return binarySearch(arr, pivot+1, arr_size-1, no);
}


int findPivot(int arr[], int low, int high)
{

   if (high < low)  return -1;
   if (high == low) return low;

   int mid = (low + high)/2;
   if (mid < high && arr[mid] > arr[mid + 1])
     return mid;
   if (mid > low && arr[mid] < arr[mid - 1])
     return (mid-1);
   if (arr[low] >= arr[mid])
     return findPivot(arr, low, mid-1);
   else
     return findPivot(arr, mid + 1, high);
}


int binarySearch(int arr[], int low, int high, int no)
{
   if (high < low)
       return -1;
   int mid = (low + high)/2;
   if (no == arr[mid])
     return mid;
   if (no > arr[mid])
     return binarySearch(arr, (mid + 1), high, no);
   else
     return binarySearch(arr, low, (mid -1), no);
}

int main()
{
   int n,i;
   cout<<"Size of array: ";
   cin>>n;
   cout<<"Enter elements: ";
   int arr1[n] ;
   for(i=0;i<n;i++)
    cin>>arr1[i];

   int arr_size = n;
   int no ;
   cout<<"Enter no to search: ";
   cin>>no;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr1, arr_size, no));


   return 0;
}
