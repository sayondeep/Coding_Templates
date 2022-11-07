//
// Created by SAYON DEEP on 04-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int>mp;

int main()
{
    int n;
    cin>>n;

    vector<int> parcels(n);
    for(int i=0;i<n;i++)
        cin>>parcels[i];

    int k;
    cin>>k;

    long long int cost=0;
    int req = k-n;
    sort(parcels.begin(),parcels.end());

    int i=0;
    int id=1;
    while(true)
    {
        if(i<n && id<parcels[i])
        {
            req--;
            cost+=id;
            cout<<id<<" ";
            id++;

            if(req==0)
            {
                break;
            }

        }
        else if(id==parcels[i])
        {
            id++;
            i++;
        }
        else
        {
            req--;
            cost+=id;
            cout<<id<<" ";
            id++;

            if(req==0)
            {
                break;
            }
        }

    }
    cout<<endl;
    cout<<cost<<endl;



    return 0;
}
