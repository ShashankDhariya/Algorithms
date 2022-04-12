#include<stdio.h>
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
}
void bubble(int arr[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<(n-1)-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    bubble(arr,num);
    print(arr,num);
}
