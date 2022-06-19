#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void actvity(int s[],int f[],int n)
{
    int i = 0;
    int j = 1;
    int ctr = 1;

    cout<<i+1<<" ";

    for(j = 1;j<n;j++)
    {
        if(f[i] <= s[j])
        {
            cout<<j+1<<" ";
            i = j;
            ctr++;
        }
    }
    cout<<endl<<"Number of non conflicting activities : "<<ctr;
}

int main()
{
    int start[] =  {1, 3, 0, 5, 8, 5};
    int finish[] =  {2, 4, 6, 7, 9, 9};
    int num = sizeof(start)/sizeof(start[0]);

    actvity(start,finish,num);
    return 0;
}
