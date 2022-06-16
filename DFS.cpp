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
    int visited[num];

    for(int i=0;i<num;i++)
        visited[i] = 0;

    vector<int> v;
    stack<int> st;

    int start;
    cout<<"Enter start symbol : ";
    cin>>start;
    st.push(start);

    while(!st.empty()){
        int temp = st.top();
        if(visited[temp] == 0){
            visited[temp] = 1;
            v.push_back(temp);
        }
        st.pop();
        for(int i=0;i<num;i++){
            if(adjMat[temp][i] == 1 && visited[i] == 0){
                st.push(i);
            }
        }
    }

    cout<<"DFS Traversal : ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" -> ";
    }
    cout<<"end";
    return 0;
}
