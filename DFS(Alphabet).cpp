#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

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

    int d[num];
    for(int i=0;i<num;i++)
        d[i] = INT_MAX;
    d[0] = 0;

    stack<int> st;

    for(int i=0;i<num-1;i++)
    {
        int visited[num];
        for(int i=0;i<num;i++)
            visited[i] = 0;

        int start = 0;
        st.push(start);

        while(!st.empty())
        {
            int temp = st.top();
            if(visited[temp] == 0)
                visited[temp] = 1;
            st.pop();

            for(int i=0;i<num;i++)
            {
                if(adjMat[temp][i] != 0 && visited[i] == 0)
                {
                    st.push(i);
                    int n = d[temp] + adjMat[temp][i];
                    if(d[i] > n)
                        d[i] = n;
                }
            }
        }
    }
    for(int i=0;i<num;i++)
        cout<<i<<" -> "<<d[i]<<endl;
    return 0;
}
