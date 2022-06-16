#include<iostream>
#include<vector>
using namespace std;

void list(vector<int>v[],int i,int j){
    v[i].push_back(j);
}

void print(vector<int>v[],int num){
    for(int i=0;i<num;i++){
        cout<<i;
        for(auto x:v[i]){
            cout<<" -> "<<x;
        }
        cout<<endl;
    }
}

int main(){

    int adjMat[5][5] = {{0,1,1,1,0},
                        {1,0,0,1,0},
                        {1,0,0,1,1},
                        {1,1,1,0,1},
                        {0,0,1,1,0}};

    int num = sizeof(adjMat)/sizeof(adjMat[0]);
    vector<int>v[num];

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(adjMat[i][j] == 1)
                list(v,i,j);
        }
    }

    print(v,num);
    return 0;
}
