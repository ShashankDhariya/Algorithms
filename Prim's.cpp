#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int adjMat[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
                        
    int num = sizeof(adjMat)/sizeof(adjMat[0]);
    
    int mst[num];
    int d[num];
    int parent[num];
    
    for(int i=0;i<num;i++)
    {
        mst[i] = 0;
        d[i] = INT_MAX;
        parent[i] = -1;
    }
    
    int src = 0;
    d[src] = 0;
    
    for(int i=0;i<num-1;i++)
    {
        int min = INT_MAX, loc;
        for(int a=0;a<num;a++)
        {
            if(!mst[a] && d[a] < min)
            {
                min = d[a];
                loc = a;
            }
        }
        mst[loc] = 1;
        
        for(int a=0;a<num;a++)
        {
            if(!mst[a] && adjMat[loc][a] && d[loc] + adjMat[loc][a] < d[a])
            {
                parent[a] = loc;
                d[a] = d[loc] + adjMat[loc][a];
            }
        }
    }
    
    for(int i=0;i<num;i++)
        cout<<parent[i]<<" -> "<<i<<endl;
        
    return 0;
}