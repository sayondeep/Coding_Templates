//
// Created by SAYON DEEP on 23-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &stalls,int &k,int mid)
{
    int n = stalls.size();
    int cows_placed=1;
    int prev_placed=stalls[0];
    for(int i=1;i<n;i++)
    {
        if(stalls[i]-prev_placed>=mid)
        {
            cows_placed++;
            prev_placed = stalls[i];
        }
    }

    return cows_placed>=k;

}
int lower_bound(vector<int> &stalls,int &k)
{


    int lo = 0;
    int hi = *max_element(stalls.begin(),stalls.end());
    int ans = 0; //based on what to return when else block not called at all (ans is not set by binary search)

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (check(stalls,k,mid))
        {
            ans = mid; //store position of 1st yes
            lo = mid + 1;


        }
        else
        {

            hi = mid - 1;

        }
    }
    return ans;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    return lower_bound(stalls,k);
}

