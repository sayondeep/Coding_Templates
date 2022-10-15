//
// Created by SAYON DEEP on 01-07-2022.
//
#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &arr,int k)
{
    int n = arr.size();

    int lo = 0;
    int hi = n - 1;
    int ans = n; //based on what to return when else block not called at all (ans is not set by binary search)

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (arr[mid]<k)
        {
            lo = mid + 1;
        }
        else
        {
            ans = mid; //store position of 1st NO
            hi = mid - 1;

        }
    }
    return ans;
}

int upper_bound(vector<int> &arr,int k)
{
    int n = arr.size();

    int lo = 0;
    int hi = n - 1;
    int ans = n; //based on what to return when else block not called at all( ans is not set by binary search)

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (arr[mid]>k)
        {
            ans = mid; //store position of 1st YES
            hi = mid - 1;

        }
        else
        {

            lo = mid + 1;

        }
    }
    return ans;
}
int main()
{

    vector<int> arr = {0,1,2,3,3,3,3,3,3,4,4,4,5};

    cout<<lower_bound(arr,3)<<endl;
    cout<<lower_bound(arr,4)<<endl;
    cout<<lower_bound(arr,6)<<endl<<endl;

    cout<<upper_bound(arr,3)<<endl;
    cout<<upper_bound(arr,4)<<endl;
    cout<<upper_bound(arr,6)<<endl;
    return 0;
}