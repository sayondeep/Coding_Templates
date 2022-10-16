//
// Created by SAYON DEEP on 16-10-2022.
//
#include <bits/stdc++.h>
using namespace std;
//int profit(int index,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>> &dp)
//{
//    int n= prices.size();
//    if(index==n || cap==0)
//        return 0;
//
//    if(dp[index][buy][cap]!=-1)
//        return dp[index][buy][cap];
//
//    int max_profit=INT_MIN;
//    if(buy)
//    {
//        int buy_now = -prices[index]+profit(index+1,0,cap,prices,dp);
//        int buy_later = profit(index+1,1,cap,prices,dp);
//
//        max_profit = max({max_profit,buy_now,buy_later});
//    }
//
//    else
//    {
//        int sell_now = prices[index]+profit(index+1,1,cap-1,prices,dp);
//
//        int sell_later = profit(index+1,0,cap,prices,dp);
//
//        max_profit = max({max_profit,sell_now,sell_later});
//
//    }
//
//    return dp[index][buy][cap]=max_profit;
//
//}
int maxProfit(int k, vector<int>& prices)
{
    int n = prices.size();
    int dp[n+1][2][k+1];

    memset(dp,0,sizeof(dp));

    for(int ind = n-1;ind>=0;ind--)
    {
        for(int buy = 0;buy<=1;buy++)
        {
            for(int cap=1;cap<=k;cap++)
            {
                int profit = 0;


                if(buy)
                    profit = max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);

                else
                    profit = max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);

                dp[ind][buy][cap] = max(profit,dp[ind][buy][cap]);
            }
        }
    }







    return dp[0][1][k];
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int k,n;
        cin>>k>>n;
        vector<int>prices(n);
        for(int i=0;i<n;i++)
        {
            cin>>prices[i];
        }

        cout<<maxProfit(k,prices)<<endl;


//        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
//        return profit(0,1,k,prices,dp);
    }
}