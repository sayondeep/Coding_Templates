//
// Created by SAYON DEEP on 24-06-2022.
//

//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118511/offering/1381543?leftPanelTab=1
#include <bits/stdc++.h>
using namespace std;

void call_bfs(vector<int> edge[],vector<int> &indeg,queue<int>&q,vector<int> &topo)
{
    while(!q.empty())
    {
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        topo.push_back(node);

        for(int v:edge[node])
        {
            indeg[v]--;
            if(indeg[v]==0)
            {

                q.push(v);
            }
        }
    }
}


vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)
{
    // Write your code here
    vector<int> edge[n];
    vector<int> indeg(n,0);

    for(vector<int> e: edges)
    {
        edge[e[0]].push_back(e[1]);
        indeg[e[1]]++;
    }
    queue<int>q;
    vector<int> topo;
    for(int i=0;i<n;i++)
    {
            if(indeg[i]==0)
            {
                q.push(i);
            }

    }
    call_bfs(edge, indeg,q, topo);

    return topo;
}