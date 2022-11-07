//
// Created by SAYON DEEP on 07-11-2022.
//
#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s,t;
    cin>>s>>t;

    int i=0,j=0;
    int n = s.length();
    int m = t.length();
    while(i<n && j<m)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }

        else
            i++;
    }
    cout<<m-j<<endl;
    return 0;
}