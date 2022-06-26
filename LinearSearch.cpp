#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool linearSrch(int arr[],int num,int key)
{
    for(int i=0;i<num;i++)
    {
        if(arr[i] == key)
            return true;
    }
    return false;
}

int main()
{
    int num;
    cout<<"Enter number of elements : ";
    cin>>num;
    int arr[num];
    cout<<"Enter elements in the array : ";
    for(int i=0;i<num;i++)
        cin>>arr[i];

    int key;
    cout<<"Enter key to be searched : ";
    cin>>key;
    bool b = false;
    b = linearSrch(arr,num,key);

    if(b)
        cout<<"Key Found"<<endl;
    else
        cout<<"Key not Found"<<endl;
    return 0;
}
