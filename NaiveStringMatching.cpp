#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void stringMatch(char* text,char* pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);

    for(int i=0;i<n-m;i++)
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(pattern[j] != text[i+j])
                break;
        }

        if(j == m)
            cout<<"Pattern found at index "<<i<<endl;
    }
}

int main()
{
    char text[] = "12345678900987654321";
    char pattern[] = "9009";

    stringMatch(text,pattern);
    return 0;
}
