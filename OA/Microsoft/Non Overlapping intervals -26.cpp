//
// Created by SAYON DEEP on 24-10-2022.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<long long int>start,end;
    vector<pair<long long int,long long int>> interval;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        start.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        end.push_back(x);
    }

    for(int i=0;i<n;i++)
    {
        interval.push_back({start[i],end[i]});
    }

    start.push_back(1e18);
    start.push_back(-1e18);
    end.push_back(1e18);
    end.push_back(-1e18);

    sort(start.begin(),start.end());
    sort(end.begin(),end.end());

    int ans=0;

    for(int i=0;i<n;i++)
    {
        int x = interval[i].first;
        int y = interval[i].second;

        int less_than= lower_bound(end.begin(),end.end(),x)-end.begin()-1;


        int more_than= start.end()-upper_bound(start.begin(),start.end(),y)-1;
        cout<<less_than<<" "<<more_than<<endl;
        ans+=(less_than*more_than);

    }

    cout<<ans;



}