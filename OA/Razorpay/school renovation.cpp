//
// Created by SAYON DEEP on 13-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    list<int>rooms;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        rooms.push_back(x);
    }

    vector<vector<int>>queries={{2,3},{3,1,1},{1,2},{3,5,7}};
    auto it = rooms.begin();
    for(vector<int>q:queries)
    {
        int t = q[0];

        if(t==1)
        {
            int m = q[1];
            for(int i=0;i<m;i++)
                it--;
        }
        if(t==2)
        {
            int m = q[1];
            for(int i=0;i<m;i++)
                it++;
        }
        if(t==3)
        {
            int x,y;
            x = q[1];
            y = q[2];
            auto it1 = ++it;
            rooms.erase(it1);
            rooms.insert(it1,x);
            ++it1;
            rooms.insert(it1,y);
        }
    }

    for(int x:rooms)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
