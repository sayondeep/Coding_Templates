//
// Created by SAYON DEEP on 28-06-2022.
//https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;

void call_dfs(int i,int p,vector<int> edges[],vector<int>&visited,int &timer,vector<int> &disc,vector<int>&low_disc,vector<vector<int>> &ans)
{
    visited[i]=1;
    disc[i]=timer;
    low_disc[i]=timer;
    timer++;

    for(int v:edges[i])
    {
        if(visited[v]==0)
        {
            call_dfs(v,i,edges,visited,timer,disc,low_disc,ans);
            //update lowest discovery due to child having back edge
            low_disc[i] = min(low_disc[i],low_disc[v]);
            //bridge check---> v saw all option it could have had
            if(low_disc[v]>disc[i])
            {
                vector<int> e;
                e.push_back(i);
                e.push_back(v);
                ans.push_back(e);
            }
        }

        else if (v!=p) //Back edge update
        {
            low_disc[i] = min(low_disc[i],disc[v]);
        }
    }



}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<vector<int>> ans;
    vector<int> edge[v];
    for(vector<int> e:edges)
    {
        edge[e[0]].push_back(e[1]);
        edge[e[1]].push_back(e[0]);
    }

    vector<int> visited(v,0);
    vector<int> disc(v),low_disc(v);

    int timer = 0;

    for(int i=0;i<v;i++)
    {
        low_disc[i]=-1;
        disc[i]=-1;
        if(visited[i]==0)
            call_dfs(i,-1,edge,visited,timer,disc,low_disc,ans);
    }



    return ans;


}

int main()
{
    return 0;
}
