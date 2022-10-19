//
// Created by SAYON DEEP on 18-10-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;

    if(str.length()&1)
    {
        cout<<"Pass"<<endl;
        return 0;
    }
    int i=0,j=str.length()/2;

    while(i<j && j<n)
    {
        if(str[i++]!=str[j++])
        {
            cout<<"Pass"<<endl;
            return 0;
        }
    }

    cout<<"Corrupted"<<endl;
    return 0;
}