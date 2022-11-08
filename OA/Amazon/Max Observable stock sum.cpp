//
// Created by SAYON DEEP on 08-11-2022.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    int k;
    cin>>k;

    unordered_map<int,int>mp;
    int ans=-1;
    int sum=0;
    for(int i=0;i<k;i++)
    {
       mp[prices[i]]++;
       sum+=prices[i];

    }

    if(mp.size()==k)
        ans=sum;


    for(int i=k;i<n;i++)
    {
        if(mp[prices[i-k]]>1)
            mp[prices[i-k]]--;
        else
            mp.erase(prices[i-k]);

        sum-=prices[i-k];

        mp[prices[i]]++;

        sum+=prices[i];

        if(mp.size()==k)
        {
            ans= max(ans,sum);
        }
    }

    cout<<ans<<endl;
    return 0;
}
