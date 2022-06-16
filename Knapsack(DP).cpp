#include<iostream>
using namespace std;

int max(int a, int b)
{
    int max = (a>b)? a:b;
    return max;
}

int main()
{
    int capacity;
    int item[] = {'A', 'B', 'C', 'D'};
    int w[] = {2, 3, 4, 5};
    int price[] = {1, 2, 5 ,6};

    cout<<"Enter capacity : ";
    cin>>capacity;

    int num = sizeof(w)/sizeof(w[0]);
    int arr[num][capacity];


    for(int i=0;i<=num;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            if(i == 0 || j == 0)
                arr[i][j] = 0;

            else if(w[i-1] <= j )
                arr[i][j] = max(arr[i-1][j], price[i-1] + arr[i-1][j - w[i-1]]);

            else
                arr[i][j] = arr[i-1][j];
        }
    }

    for(int i=0;i<=num;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Maximum profit : Rs."<<arr[num][capacity];
    return 0;
}
