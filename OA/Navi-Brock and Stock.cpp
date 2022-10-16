//
// Created by SAYON DEEP on 16-10-2022.
//
#include <bits/stdc++.h>
using namespace std;

int profit(int index,int txn,int k, vector<int>& prices,vector<vector<int>> &dp)
{
    int n = prices.size();
    if(index==n || txn == 2*k)
        return 0;

    if(dp[index][txn]!=-1)
        return dp[index][txn];

    int max_profit= 0;
    if(txn%2==0)
    {
        max_profit = max(-prices[index]+profit(index+1,txn+1,k,prices,dp),profit(index+1,txn,k,prices,dp));
    }
    else
    {
        max_profit = max(prices[index]+profit(index+1,txn+1,k,prices,dp),profit(index+1,txn,k,prices,dp));
    }

    return dp[index][txn]=max_profit;
}
int maxProfit(int k, vector<int>& prices)
{
    int n = prices.size();

//         vector<vector<int>> dp(n,(vector<int>(2*k,-1)));

//         return profit(0,0,k,prices,dp);

    vector<vector<int>> dp(n+1,(vector<int>(2*k+1,0)));

    for(int index=n-1;index>=0;index--)
    {
        for(int txn=0;txn<2*k;txn++)
        {
            int max_profit= 0;
            if(txn%2==0)
            {
                max_profit = max(-prices[index]+profit(index+1,txn+1,k,prices,dp),profit(index+1,txn,k,prices,dp));
            }
            else
            {
                max_profit = max(prices[index]+profit(index+1,txn+1,k,prices,dp),profit(index+1,txn,k,prices,dp));
            }

            dp[index][txn]=max_profit;
        }

    }


    return dp[0][0];

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
    }
}