#include<stdio.h>
void print(int arr[],int n)
{
    printf("\nElements are : ");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
}

void merge(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {

    }
}

int main()
{
    int num;
    printf("Enter number of elements : ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter elements : ");
    for(int i=0;i<num;i++)
        scanf("%d",arr+i);
    merge(arr,num);
    print(arr,num);
}
