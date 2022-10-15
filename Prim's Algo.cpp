//
// Created by SAYON DEEP on 29-06-2022.
//https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.

    vector<pair<int,int>> edge[n+1];
    for(auto e:g)
    {
        edge[e.first.first].push_back({e.first.second,e.second});
        edge[e.first.second].push_back({e.first.first,e.second});
    }

    vector<int> mst(n+1,0),parent(n+1,-1),dist(n+1,INT_MAX);

    dist[1]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mini;

    mini.push({0,1});

    while(!mini.empty()) //till n nodes are added to the MST
    {
        auto p = mini.top();
        mini.pop();

        int u= p.second;
        mst[u]=1;

        for(pair<int,int> e: edge[u])
        {
            int v = e.first;
            int w = e.second;

            if(mst[v]==0 && dist[v]>w)
            {

                dist[v]=w;
                parent[v]=u;
                mini.push({w, v});
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++)
    {
        ans.push_back({{parent[i],i},dist[i]});
    }

    return ans;


}

int main()
{

}