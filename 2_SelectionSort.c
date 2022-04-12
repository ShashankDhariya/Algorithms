#include<stdio.h>
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
}
void selection(int arr[],int n)
{
    int min;
    int temp, loc;
    for(int i=0;i<n;i++)
    {
        int ctr = 0;
        min = arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < min)
            {
                min = arr[j];
                loc = j;
                ctr++;
            }
        }
        if(ctr > 0)
        {
            temp = arr[i];
            arr[i] = arr[loc];
            arr[loc] = temp;
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
    selection(arr,num);
    print(arr,num);
}
