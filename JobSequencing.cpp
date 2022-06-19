#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j)
{
    int temp = arr[i];
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
    char jobs[] = {'a','b', 'c', 'd', 'f', 'g', 'h', 'i'};
    int deadline[] = {2, 6, 6, 5, 4, 2, 4, 3};
    int profit[] = {80, 70, 65, 60, 25, 22, 20, 10};
    int num = sizeof(profit)/sizeof(profit[0]);

    for(int i=0;i<num-1;i++)
    {
        for(int j=0;j<(num-1)-i;j++)
        {
            if(profit[j] < profit[j+1])
            {
                swap(profit,j,j+1);
                swap(jobs,j,j+1);
                swap(deadline,j,j+1);
            }
        }
    }

    int maxd = INT_MIN;
    for(int i=0;i<num;i++)
    {
        if(deadline[i] > maxd)
            maxd = deadline[i];
    }

    int ans = 0;
    int job = 0;
    int result[maxd];
    for(int i=0;i<num;i++)
        result[i] = -1;

    for(int i=0;i<num;i++)
    {
        // Free slots
        for(int j = deadline[i]-1;j>=0;j--)
        {
            if(result[j] == -1)
            {
                result[j] = 0;
                job++;
                ans += profit[i];
                break;
            }
        }
    }

    cout<<"Profit : Rs."<<ans<<endl;
    cout<<"No. of jobs : "<<job<<endl;
    return 0;
}
