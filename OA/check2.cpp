//
// Created by SAYON DEEP on 17-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x=0;

    int y=0;

    for(int i=1;i<=23;i++)
        x^=i;

    for(int i=1;i<=21;i++)
        y^=i;


    cout<<x<<endl;
    cout<<y<<endl;
    cout<<(x^y)<<endl;
    return 0;
}