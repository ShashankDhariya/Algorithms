#include<iostream>
#include<stack>
using namespace std;

stack<int> topo(stack<int>&st,int visited[],int a,int adjMat[6][6])
{
    int num = 6;
    visited[a] = 1;
    for(int i=0;i<num;i++)
    {
        if(adjMat[a][i] && !visited[i])
            topo(st,visited,i,adjMat);
    }
    
    st.push(a);
    cout<<"Stack :"<<st.top()<<endl;
    return st;
}

int main()
{
    int adjMat[6][6] = {{0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0}}; 
                    
    int num = sizeof(adjMat)/sizeof(adjMat[0]);
    int visited[num];
    stack<int> st;
    for(int i=0;i<num;i++)
        visited[i] = 0;
    
    for(int i=0;i<num;i++)
    {
        if(visited[i] == 0)
            st = topo(st,visited,i,adjMat);
    }
    
    while(!st.empty())
    {
        cout<<st.top()<<" -> ";
        st.pop();
    }
    return 0;
}
