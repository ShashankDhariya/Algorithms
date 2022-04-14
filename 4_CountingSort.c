#include<stdio.h>
void get(int arr[],int n)
{
    printf("Enter elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);
}

void print(int arr[],int n)
{
    printf("Elements are : ");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
}

int max(int arr[],int n)
{
    int large = -10000;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>large)
            large = arr[i];
    }
    return large;
}

void change_arr1(int arr1[],int n)
{
    for(int i=1;i<n+1;i++)
    {
        arr1[i] += arr1[i-1];
    }
}

void countingSort(int arr[],int n)
{
    int l = max(arr,n);
    int arr1[10] = {0};
    for(int i=0;i<=l;i++)
        arr1[arr[i]]++;

    change_arr1(arr1,l);

    int arr2[10];
    for(int i=0;i<=l;i++)
    {
        arr2[arr1[arr[i]]] = arr[i];
        arr1[arr[i]]--;
    }

    printf("\n\nAfter Sorting : \n");
    print(arr2+1,l+1);
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
    countingSort(arr,num);

}
