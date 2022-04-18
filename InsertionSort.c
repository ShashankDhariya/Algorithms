#include<stdio.h>
void get(int arr[],int n)
{
    printf("Enter elements : ");
    for(int i =0;i<n;i++)
        scanf("%d",arr+i);
}

void print(int arr[],int n)
{
    printf("Elements are : ");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
}

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && temp<arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int num;
    printf("Enter number of elements : ");
    scanf("%d",&num);
    int arr[num];
    get(arr,num);
    printf("Before Sorting : \n");
    print(arr,num);
    printf("After Sorting : \n");
    inserttionSort(arr,num);
    print(arr,num);
    return 0;
}
