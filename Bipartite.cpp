#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bipartite(int adjMat[5][5],int num)
{
    int src;
    cout<<"Enter source : ";
    cin>>src;

    stack<int> st;
    st.push(src);

    int color[num];
    for(int i=0;i<num;i++)
        color[i] = 1;

    color[src] = 0;

    while(!st.empty())
    {
        int temp = st.top();
        st.pop();

        if(adjMat[temp][temp] == 1)
            return 0;

        for(int i=0;i<num;i++)
        {
            if(adjMat[temp][i] && color[i] == -1)
            {
                color[i] = 1 - color[temp];
                st.push(i);
            }

            else if(adjMat[temp][i] && color[temp] == color[i])
                return false;
        }
    }
    return true;
}

int main()
{
    int adjMat[5][5] = {{0,1,1,1,0},
                        {1,0,0,1,0},
                        {1,0,0,1,1},
                        {1,1,1,0,1},
                        {0,0,1,1,0}};

    int num = sizeof(adjMat)/sizeof(adjMat[0]);
    bool b = bipartite(adjMat,num);
    if(b)
        cout<<"Bipartite"<<endl;
    else
        cout<<"Not bipartite"<<endl;
    return 0;
}
