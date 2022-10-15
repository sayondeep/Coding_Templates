//
// Created by SAYON DEEP on 01-07-2022.
//https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;
void call_bfs(int i,vector<int> edges[],vector<int>&visited,vector<int> &dist,vector<int>&parent)
{
    visited[i]=1;
    dist[i]=0;
    queue<int> q;
    q.push(i);

    while(!q.empty())
    {

        int u = q.front();


        q.pop();

        for(int v:edges[u])
        {
            if(visited[v]==0)
            {
                visited[v]=1;
                dist[v]= dist[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t)
{

    // Write your code here
    vector<int> edge[n+1];
    vector<int> dist(n+1,INT_MAX),visited(n+1,0),parent(n+1,-1);
    for(pair<int,int> e: edges)
    {
        edge[e.first].push_back(e.second);
        edge[e.second].push_back(e.first);
    }

    call_bfs(s,edge,visited,dist,parent);

    vector<int> ans;
    int i = t;
    while(parent[i]!=-1)
    {
        ans.insert(ans.begin(),parent[i]);
        i = parent[i];
    }
    ans.push_back(t);

    return ans;



}
int main()
{
    return 0;
}
