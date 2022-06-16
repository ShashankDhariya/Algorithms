#include<iostream>
using namespace std;

void swap(int arr[],int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swap(float arr[],int i,int j)
{
    float temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swap(char arr[],int i,int j)
{
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    int capacity;
    cout<<"Enter capacity : ";
    cin>>capacity;

    char item[] = {'A','B','C','D','E'};
    int cost[] = {20,50,30,8,10};
    int qty[] = {5,2,15,8,20};

    int num = sizeof(cost)/sizeof(cost[0]);

    float cpw[num];
    int profit = 0;

    for(int i=0;i<num;i++)
        cpw[i] = (float)cost[i]/qty[i];

    for(int i=0;i<num-1;i++)
    {
        for(int j=0;j<(num-1)-i;j++)
        {
            if(cpw[j] < cpw[j+1])
            {
                swap(cpw,j,j+1);
                swap(item,j,j+1);
                swap(qty,j,j+1);
                swap(cost,j,j+1);
            }
        }
    }

    for(int i=0;i<num;i++)
    {
        if(capacity >= qty[i])
        {
            cout<<"Item Picked : "<<item[i]<<endl;
            profit += cost[i];
            capacity -= qty[i];
            cout<<"Weight : "<<qty[i]<<endl;
            cout<<"Profit : "<<cost[i]<<endl<<endl;
        }
        else
        {
            cout<<"Item Picked : "<<item[i]<<endl;
            profit += (capacity*cpw[i]);
            cout<<"Weight : "<<capacity<<endl;
            cout<<"Profit : "<<profit<<endl<<endl;
            capacity = 0;
            break;
        }
    }
    cout<<"Net Profit : Rs. "<<profit<<endl;
    return 0;
}
