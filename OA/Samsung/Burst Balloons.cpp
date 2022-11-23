//
// Created by SAYON DEEP on 23-11-2022.
//
#include<bits/stdc++.h>
int pts(int i,int j,vector<int>&a,vector<vector<int>>&dp)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int maxi = INT_MIN;
    for(int k = i;k<=j;k++)
    {
        int point = a[k]*a[i-1]*a[j+1]+pts(i,k-1,a,dp)+pts(k+1,j,a,dp);

        maxi = max(maxi,point);
    }

    return dp[i][j]=maxi;
}


int maxCoins(vector<int>& a)
{
    // Write your code here.
    int n = a.size();
    a.push_back(1);
    a.insert(a.begin(),1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    //return pts(1,n,a,dp);

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j)
                continue;
            int maxi = INT_MIN;
            for(int k = i;k<=j;k++)
            {
                int point = a[k]*a[i-1]*a[j+1]+dp[i][k-1]+dp[k+1][j];

                maxi = max(maxi,point);
            }

            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}