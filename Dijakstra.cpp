#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int FindMin(bool spt[],int d[],int num)
{
    int min = INT_MAX;
    int loc;
    for(int i=0;i<num;i++)
    {
        if(spt[i] == false && d[i] < min)
        {
            min = d[i];
            loc = i;
        }
    }
    return loc;
}

int main()
{
    int adjMat[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
    int num = sizeof(adjMat)/sizeof(adjMat[0]);
        
    int weight[num];
    for(int i=0;i<num;i++)
        weight[i] = INT_MAX;
    weight[0] = 0;
    
    bool spt[num];
    for(int i=0;i<num;i++)
        spt[i] = false;
    
    for(int i=0;i<num;i++)
    {
        int u = FindMin(spt,weight,num);
        spt[u] = true;
            
        for(int i=0;i<num;i++)
        {
            if(!spt[i] && adjMat[u][i]  && weight[u] != INT_MAX && weight[u] + adjMat[u][i] < weight[i])
                weight[i] = weight[u] + adjMat[u][i];
        }
    }
    
    for(int i=0;i<num;i++)
        cout<<i<<" -> "<<weight[i]<<endl;
    return 0;
} 