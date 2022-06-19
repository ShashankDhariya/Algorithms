#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    int m = (a>b)? a:b;
    return m;
}

void LCS(char* str1,char* str2)
{
    int n = strlen(str1);
    int m = strlen(str2);
    int LCS[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            LCS[i][j] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i] == str2[j])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<LCS[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Longest common subsequence : "<<LCS[n][m];
}

int main()
{
    char str1[] = "Stone";
    char str2[] = "Longest";

    LCS(str1,str2);
    return 0;
}
