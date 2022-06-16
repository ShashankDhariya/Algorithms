#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    int num, e;
    cout<<"Enter number of vertices and edge : ";
    cin>>num>>e;
    
    vector<node>edges;
    
    for(int i=0;i<e;i++)
    {
        int u, v, weight;
        cout<<"Nodes and weight : ";
        cin>>u>>v>>weight;
        edges.push_back(node(u, v, weight));
    }
    
    int inf = 100000;
    vector<int> dist(num,inf);
    
    int src;
    cout<<"Enter source vertex : ";
    cin>>src;
    
    dist[src] = 0;
    
    for(int i=0;i<num-1;i++)
    {
        for(auto x : edges)
        {
            if(dist[x.u] + x.wt < dist[x.v])
                dist[x.v] = dist[x.u] + x.wt;
        }
    }
    
    int fl = 0;
    
    for(auto x : edges)
    {
        if(dist[x.u] + x.wt < dist[x.v])
        {
            cout<<"Negative cycle detected"<<endl;
            fl = 1;
            break;
        }
    }
    
    if(!fl)
    {
        for(int i=0;i<num;i++)
        {
            cout<<i<<" -> "<<dist[i]<<endl;
        }
    }
    return 0;
}
