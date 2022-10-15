//
// Created by SAYON DEEP on 30-06-2022.
//https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h>
using namespace std;

void relax(int src,vector<pair<int,int>> edge[],vector<int>&dist,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> &mini)
{
    for(pair<int,int> e: edge[src])
    {
        int w = e.second;
        if(dist[e.first]>dist[src]+w)
        {
            dist[e.first]=dist[src]+w;
            mini.push({w,e.first});
        }
    }
}



vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.

    vector<pair<int,int>> edge[vertices];

    for(vector<int> e: vec)
    {
        edge[e[0]].push_back({e[1],e[2]});
        edge[e[1]].push_back({e[0],e[2]});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mini;

    vector<int> dist(vertices,INT_MAX);

    dist[source]=0;
    mini.push({0,source});

    while(!mini.empty())
    {
        int src = mini.top().second;
        mini.pop();
        relax(src,edge,dist,mini);
    }


    return dist;
}

int main()
{
    return 0;
}