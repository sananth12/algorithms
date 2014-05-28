#include<iostream>
using namespace std;
void merge(int *arr,int l,int mid,int r)
{
  int tmp[r-l+1],i=0,posr=mid+1,posl=l;
  while(posl<=mid && posr<=r )
    {
      if(arr[posl]<arr[posr])
	{ 
	  tmp[i]=arr[posl];
	  posl++;
	}
      else
	{
	  tmp[i]=arr[posr];
	  posr++;
	}
      i++;
    }
  while(posl<=mid)
   tmp[i++]=arr[posl++];
  while(posr<=r)
    tmp[i++]=arr[posr++];

  for(int j=0;j<i;j++)
      arr[l+j]=tmp[j];
}

void mergesort(int *arr,int l,int r)
{
  int mid= (l+r)/2;
   if(l<r)
    {
      mergesort(arr,l,mid);
      mergesort(arr,mid+1,r);
      merge(arr,l,mid,r);
    }
}
int main()
{
  int n,i,j;
  cout<<"Size: ";
  cin>>n;
  int arr[n];
  cout<<"enter the numbers:\n";
  for(i=0;i<n;i++)
    cin>>arr[i];
  
  mergesort(arr,0,n-1);
  for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
  
  return 0;
}
