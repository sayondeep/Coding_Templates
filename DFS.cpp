//
// Created by SAYON DEEP on 24-06-2022.
//
#include<bits/stdc++.h>
using namespace std;

void call_dfs(int i,vector<int> edges[],vector<int>&visited)
{
    visited[i]=1;
    cout<<i<<" ";

    for(int v:edges[i])
    {
        if(visited[v]==0)
            call_dfs(v,edges,visited);
    }
}


int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> edges[n];
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);

    }

    vector<int> visited(n,0);


    for (int i = 0; i < n; i++) {
        if (visited[i]==0)
            call_dfs(i,edges,visited);
    }

    return 0;
}