#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int adjMat[6][6] = {{0, 1, 0, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0},
                        {0, 0, 0, 1, 0, 1},
                        {0, 0, 0, 0, 0, 1},
                        {1, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0}};

    int num = sizeof(adjMat)/sizeof(adjMat[0]);

    vector<int>v;
    stack<int>st;
    int visited[num];
    for(int i=0;i<num;i++)
        visited[i] = 0;

    int stackState[num];
    for(int i=0;i<num;i++)
        stackState[i] = 0;

    int start = 0;
    st.push(0);

    while(!st.empty())
    {
        int temp = st.top();
        stackState[temp] = 1;
        if(visited[temp] == 0)
            visited[temp] = 1;

        st.pop();

        for(int i=0;i<num;i++)
        {
            if(adjMat[temp][i] == 1 && visited[i] == 0)
            {
                st.push(i);
                stackState[i] = 1;
            }
            else if(adjMat[temp][i] == 1 && stackState[i] == 1)
            {
                cout<<"Cycle Found"<<endl;
                return 0;
            }
        }
    }
    cout<<"Cycle Not Found";
    return 0;
}
