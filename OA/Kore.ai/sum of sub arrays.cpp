//
// Created by SAYON DEEP on 19-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int calculateMaxSumLength(vector<int> &arr,int k)
{
    int n = arr.size();
    int ans = 0;
    int count = 0;
    int flag = 0;

    for (int i = 0; i < n;)
    {
        count = 0;
        flag = 0;
        while (arr[i] <= k && i < n)
        {
            count++;
            if (arr[i] == k)
                flag = 1;
            i++;
        }

        if (flag == 1)
            ans += count;
        while (arr[i] > k && i < n)
            i++;
    }
    return ans;
}

int main()
{

    int n;
    cin>>n;
    vector<int> arr(n);
    int k;
    cin>>k;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<calculateMaxSumLength(arr,k);
    return 0;
}