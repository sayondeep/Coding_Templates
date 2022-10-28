//
// Created by SAYON DEEP on 04-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> compress(vector<int>&arr)
{
    if(arr.size()==2)
        return arr;

    vector<int> temp;

    for(int i=1;i<arr.size();i++)
    {
        temp.push_back((arr[i]+arr[i-1])%10);
    }

    return compress(temp);
}

int main()
{

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    string ans="";
    vector<int> temp=compress(arr);

    for(int i:temp)
    {
        ans+=(to_string(i));
    }

    cout<<ans<<endl;
    return 0;

}