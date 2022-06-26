#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool linearSrch(int arr[],int l,int h,int key)
{
    int mid = (l+h)/2;
    if(l<h)
    {
        if(arr[mid] == key)
            return true;
        else if(key < arr[mid])
            return linearSrch(arr,l,mid,key);
        else if(key > arr[mid])
            return linearSrch(arr,mid+1,h,key);
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
    b = linearSrch(arr,0,num,key);

    if(b)
        cout<<"Key Found"<<endl;
    else
        cout<<"Key not Found"<<endl;
    return 0;
}
