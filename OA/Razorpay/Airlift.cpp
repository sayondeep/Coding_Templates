//
// Created by SAYON DEEP on 13-11-2022.
//
//
// Created by SAYON DEEP on 04-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;

    int n;
    cin>>n;
    vector<int>awards(n);
    for(int i=0;i<n;i++)
        cin>>awards[i];


    sort(awards.begin(),awards.end());


    int i=0,j=n-1;
    int group=0;
    while(i<j)
    {
        if(awards[i]>k || awards[j]>k)
        {
            cout<<"-1";
            break;
        }
        else if(awards[i]+awards[j]>k)
        {
            group++;
            j--;
        }

        else
        {
            group++;
            i++;
            j--;
        }
    }

    cout<<group<<endl;
    return 0;
}
