#include<stdio.h>

void print(int arr[],int n)
{
    printf("Elements are : ");
    for(int i = 0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
}

void quickSort(int arr[],int start,int n)
{
    if(start < n)
    {
        int pivot = start;
        int  i = pivot+1;
        int j = n-1;
    while(i<j)
    {
        while(arr[i] < arr[pivot] && i < n)
            i++;

        while(arr[j] > arr[pivot])
            j--;

        if(i<n)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quickSort(arr,start,j-1);
    }
}

int main()
{
    int arr[] = {5, 2, 3, 6, 7, 9, 1, 8, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size);
    return 0;
}
