#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int adjMat[5][5] = {{0,1,1,1,0},
                        {1,0,0,1,0},
                        {1,0,0,1,1},
                        {1,1,1,0,1},
                        {0,0,1,1,0}};

    int num = sizeof(adjMat)/sizeof(adjMat[0]);

    vector<int> v;
    queue<int> q;
    int visited[num];
    for(int i=0;i<num;i++)
        visited[i] = 0;

    int start;
    cout<<"Enter starting node : ";
    cin>>start;
    q.push(start);
    while(! q.empty())
    {
        int temp = q.front();
        if(visited[temp] == 0)
        {
            visited[temp] = 1;
            v.push_back(temp);
        }
        q.pop();

        for(int i=0;i<num;i++)
        {
            if(adjMat[temp][i] == 1 && visited[i] == 0)
            {
                q.push(i);
            }
        }
    }

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" -> ";
    cout<<"end"<<endl;
    return 0;
}
