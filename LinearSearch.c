#include<stdio.h>

void get(int arr[],int *num)
{
    printf("Enter values : ");
    for(int i=0;i<*num;i++)
        scanf("%d",&arr[i]);
}

int srch(int arr[],int *num,int *key)
{
    for(int i=0;i<*num;i++)
    {
        if(arr[i] == *key)
            return 1;
    }
    return 0;
}
int main()
{
    int num;
    printf("Enter number of Elements : ");
    scanf("%d",&num);
    int arr[num];
    get(arr,&num);
    int key;
    printf("Enter key to be searched : ");
    scanf("%d",&key);
    int r = srch(arr,&num,&key);
    if(r == 1)
        printf("%d found\n",key);
    else
        printf("%d not found\n",key);
    return 0;
}
