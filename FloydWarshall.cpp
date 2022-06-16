#include<iostream>
#include<bits/stdc++.h>
#define inf 10000
using namespace std;

int main()
{
    int d[4][4] = {{0, 1, 3, 2},
                   {inf, 0, 1, 2},
                   {2, inf, 0, 4},
                   {inf, 1, inf, 0}};

    int num = sizeof(d)/sizeof(d[0]);

    for(int k=0;k<num;k++)
    {
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(d[i][j] == inf)
                cout<<"I ";
            else
                cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
