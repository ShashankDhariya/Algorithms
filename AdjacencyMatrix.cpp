#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter number of nodes in the Graph : ";
    cin>>num;
    int adjMat[num][num];

    int edge;
    cout<<"Enter number of edges : ";
    cin>>edge;

    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
            adjMat[i][j] = 0;
    }

    int a, b;
    for(int i=0;i<edge;i++){
        cout<<"Enter connected nodes : ";
        cin>>a>>b;
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }

    cout<<"Adjacency Matrix is : "<<endl;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
            cout<<adjMat[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
