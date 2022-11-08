//
// Created by SAYON DEEP on 08-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>pnl(n);

    for(int i=0;i<n;i++)
    {
        cin>>pnl[i];
    }

    int k;
    cin>>k;

    priority_queue<int> neg;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(pnl[i]>=0)
            sum+=pnl[i];
        else
            neg.push(pnl[i]);
    }

    int e=0;
    int sub=0;
    while(e<k&& !neg.empty())
    {
        sub+=(neg.top());
        e++;
        neg.pop();
    }
    int ans;
    sum+=sub;

    if(e<k)
        ans=-1;
    else if(sum<0)
        ans=-1;
    else
        ans = sum;

    cout<<ans<<endl;



    return 0;
}