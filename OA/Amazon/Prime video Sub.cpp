//
// Created by SAYON DEEP on 04-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    vector<int>awards(n);
    for(int i=0;i<n;i++)
        cin>>awards[i];

    int k;
    cin>>k;

    sort(awards.begin(),awards.end());

    int ref=awards[0];
    int groups=1;
    for(int i=1;i<n;i++)
    {
         if(awards[i]<= ref+k)
             continue;
        else
        {
            ref= awards[i];
            groups++;
        }

    }

    cout<<groups<<endl;
    return 0;
}
