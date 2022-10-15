//
// Created by SAYON DEEP on 24-06-2022.
//

#include <bits/stdc++.h>
using namespace std;


void call_bfs01(int i,vector<pair<int,int>> edges[],vector<int>&dist)
{
    dist[i]=0;
    deque<int> dq;
    dq.push_back(i);

    while(!dq.empty())
    {
        int node = dq.front();
        // cout<<node<<" ";
        dq.pop_front();
        for(pair<int,int> n:edges[node])
        {
            int v=n.first;
            int wt = n.second;

            if(dist[v]>dist[node]+wt)
            {
                dist[v]=dist[node]+wt;
                if(wt==0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }
}


int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int,int>> edges[n+1];
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edges[a].push_back({b, 0});
        edges[b].push_back({a, 1});

    }

    vector<int> dist(n+1,INT_MAX);


    /*for (int i = 0; i < n; i++) {
        if (visited[i]==0)
            call_bfs(i,edges,visited);
    }*/
    call_bfs01(1,edges,dist);

    cout<<dist[n];
    return dist[n]==INT_MAX?-1:dist[n];
}

