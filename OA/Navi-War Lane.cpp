//
// Created by SAYON DEEP on 16-10-2022.
//
#include <bits/stdc++.h>
using namespace std;

int min_dist(vector<int>&pos,int l)
{
    pos.insert(pos.begin(),0);
    pos.push_back(l);

    int max_dist = INT_MIN;
    for(int i=1;i<pos.size();i++)
    {
        max_dist = max(max_dist,pos[i]-pos[i-1]);
        //cout<<max_dist<<" ";
    }
    //cout<<endl;

    if(max_dist%2==0)
        return max_dist/2;
    else
        return max_dist/2+1;

}

int main()
{
    int n,l;
    cin>>n>>l;
    vector<int>pos;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        pos.push_back(p);
    }

    cout<<min_dist(pos,l)<<endl;
}
