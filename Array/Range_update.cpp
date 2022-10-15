//
// Created by SAYON DEEP on 07-08-2022.
//
#include <bits/stdc++.h>
using namespace std;

void range_update(vector<int>&arr,int l,int r,int k)
{
    arr[l]+=k;
    if(r+1<arr.size())
    arr[r+1]-=k;
}

int main()
{

    int n;
    cout<<"Enter the # of elements"<<endl;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int q;
    cout<<"Enter the # of queries"<<endl;
    cin>>q;
    int l,r,k;
    vector<int>diff(n);
    diff[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        diff[i]=arr[i]-arr[i-1];
    }
    while(q--)
    {
        cin>>l>>r>>k;
        range_update(diff,l,r,k);
    }

    for(int i=1;i<n;i++)
    {
        diff[i]=diff[i]+diff[i-1];
    }


    for(int e:diff)
    {
        cout<<e<<" ";
    }
    cout<<endl;
}