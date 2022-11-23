//
// Created by SAYON DEEP on 23-11-2022.
//
#include<bits/stdc++.h>
int tsp(vector<vector<int>> &dist,int visit_mask,int curr_city,vector<vector<int>> &dp)
{
    int n = dist.size();

    if(visit_mask==(1<<n)-1)
        return dist[curr_city][0];
    if(dp[visit_mask][curr_city]!=-1)
        return dp[visit_mask][curr_city];

    int min_path = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if((visit_mask & (1<<i))==0)
        {
            int n_visit_mask= visit_mask|(1<<i);
            int path = dist[curr_city][i] + tsp(dist,n_visit_mask,i,dp);

            min_path = min(min_path,path);
        }
    }

    return dp[visit_mask][curr_city]=min_path;
}

int shortestRoute(vector<vector<int>> &dist)
{
    // Write your code here.
    int n = dist.size();
    vector<vector<int>> dp(1<<n,vector<int>(n,-1));
    return tsp(dist,1,0,dp);
}