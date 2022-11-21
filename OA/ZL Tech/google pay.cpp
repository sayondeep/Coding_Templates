//
// Created by SAYON DEEP on 19-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solve (int n,vector<vector<string>> &A,string D, string V)
{
    unordered_map<string,int> mp;
    mp["bank_account_number"]=0;
    mp["account_holder_first_name"]=1;
    mp["account_holder_last_name"]=2;
    mp["registered_mobile_number"]=3;
    mp["branch_code"]=4;

    int offset = mp[D];
    vector<vector<string>> ans;
    for(vector<string>detail:A)
    {
        if(detail[offset]==V)
        {
            ans.push_back(detail);
        }
    }

    return ans;
}
int main()
{

    int n;
    cin>>n;

    return 0;
}