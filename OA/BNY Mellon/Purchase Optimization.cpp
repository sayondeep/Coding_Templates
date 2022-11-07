//
// Created by SAYON DEEP on 07-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++)
        cin>>prices[i];

    vector<int>pref(n,0);
    pref[0]=prices[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+prices[i];
    }

    int q;
    cin>>q;
    vector<int>pos(q),amount(q);

    for(int i=0;i<q;i++)
    {
        cin>>pos[i];
    }
    int r;
    cin>>r;
    for(int i=0;i<q;i++)
    {
        cin>>amount[i];
    }
    for(int j=0;j<q;j++)
    {
        int i = pos[j]-1;
        int amt = amount[j];

        int cost;
        if(i==0)
            cost=pref[0];
        else
            cost = pref[i]-pref[i-1];

        if(cost>amt)
            cout<<"0"<<endl;
        else
        {
            auto it = upper_bound(pref.begin()+i,pref.end(),pref[i]+amt-cost);
            cout<<pref[i]+amt-cost<<endl;
            if(it==pref.end())
                cout<<"isend"<<endl;

            int index = it - (pref.begin()+i);

            cout<<index<<endl;


        }
    }

    return 0;
}