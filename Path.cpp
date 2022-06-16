#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int adjMat[5][5] = {{0,1,1,1,0},
                        {1,0,0,1,0},
                        {1,0,0,1,1},
                        {1,1,1,0,1},
                        {0,0,1,1,0}};

    int num = sizeof(adjMat)/sizeof(adjMat[0]);

    vector<int> v;
    stack<int> st;
    int visited[num];

    for(int i=0;i<num;i++)
        visited[i] = 0;

    int start;
    int des;
    cout<<"Enter starting node : ";
    cin>>start;
    cout<<"Enter destination node : ";
    cin>>des;
    st.push(start);

    while(!st.empty())
    {
        int temp = st.top();
        if(visited[temp] == 0)
        {
            visited[temp] = 1;
            v.push_back(temp);
        }
        st.pop();
        for(int i=0;i<num;i++)
        {
            if(adjMat[temp][i] == 1 && visited[i] == 0)
            {
                st.push(i);
            }
        }
    }

    bool b = false;
    for(int i=0;i<num;i++)
    {
        if(v[i] == des)
            b = true;
    }

    if(b == true)
        cout<<"Path exists"<<endl;
    else
        cout<<"Path doesn't exist"<<endl;

    return 0;
}
