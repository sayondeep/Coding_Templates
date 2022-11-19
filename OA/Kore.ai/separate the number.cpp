//
// Created by SAYON DEEP on 19-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
    vector<int>arr;
    int sum=0;
    while(n>0)
    {
        int r = n%10;
        sum+=r;
        n=n/10;
        arr.push_back(r);
    }
    sort(arr.begin(),arr.end());
    int c=0;

    int sz = arr.size();

    for(int e:arr)
    {
        if(sum>17)
        {
            c++;
            sum-=e;
        }
        else
            break;
    }

    if(c==sz-1)
        return true;
    else
        return false;


}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    int mask=1;
    for(int i=0;i<n;i++)
    {
        if(check(arr[i]))
        {
            int c= mask<<i;
            ans+=c;
            //cout<< c<<" ";
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
4
11
399
899
9944
 */