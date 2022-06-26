#include<iostream>
using namespace std;

void TOH(char src,char inter,char dest,int n)
{
    if(n == 1)
    {
        cout<<"Move disc from "<<src<<" to "<<dest<<endl;
        return;
    }
    else
    {
        TOH(src,dest,inter,n-1);
        cout<<"Move disc from "<<src<<" to "<<dest<<endl;
        TOH(inter,src,dest,n-1);
    }
}

int main()
{
    int num;
    cout<<"Enter number of Discs : ";
    cin>>num;

    char a = 'A', b = 'B', c = 'C';

    TOH(a,b,c,num);
    return 0;
}
