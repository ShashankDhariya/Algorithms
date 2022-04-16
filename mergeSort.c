#include<stdio.h>

void print(int arr[],int n)
{
    printf("Elements are : ");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
}

void merge(int arr[],int s,int mid,int n)
{
    int left[mid+1] ,right[n-mid+1];
    for(int i=0;i<mid;i++)
        left[i] = arr[i];

    for(int i=0;i<n-mid;i++)
        right[i] = arr[mid+i];

    left[mid] = 10000;
    right[n-mid] = 10000;

    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(left[x]<=right[y])
            arr[i] = left[x++];
        else
            arr[i] = right[y++];
    }
}

void divide(int arr[],int s,int n)
{
    if(s<n)
    {
        int mid = (s+n)/2;
        divide(arr,s,mid);
        divide(arr,mid+1,n);
        merge(arr,s,mid,n);
    }
}

int main()
{
    int arr[] = {2,5,8,2,6,8,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    divide(arr,0,size);
    print(arr,size);
}
