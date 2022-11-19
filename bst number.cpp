//
// Created by SAYON DEEP on 12-11-2022.
//
#include <bits/stdc++.h>
#define mod 100000007
using namespace std;

long long  get_num(int n, vector<long long int> &dp)
{
    if(n==0)
        return 1;

    else if(n==1)
        return 1;


    if(dp[n]!=-1)
        return dp[n];

    long long int ans=0;

    for(int i=1;i<=n;i++)
    {
        int root = i;

        ans+= 1LL*((get_num(root-1,dp)%mod)* (get_num(n-root,dp)%mod));

    }


    return dp[n]=ans;
}

int numTrees(int n)
{

    vector<long long int> dp(n+1,-1);

    return get_num(n,dp)%mod;


}
int main()
{

    cout<< numTrees(1000)<<endl;
    return 0;
}