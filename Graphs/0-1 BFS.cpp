//
// Created by SAYON DEEP on 13-08-2022.
//

#include<bits/stdc++.h>
using namespace std;

void call_bfs01(int i,vector<pair<int,int>> edges[],vector<int>&dist)
{
    dist[i]=0;
    deque<int> dq;
    dq.push_back(i);

    while(!dq.empty())
    {
        int node = dq.front();
        cout<<node<<" ";
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

    vector<pair<int,int>> edges[n];
    int a, b,c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});

    }

    vector<int> dist(n,INT_MAX);


    for (int i = 0; i < n; i++) {
        if (visited[i]==0)
            call_bfs(i,edges,visited);
    }

    return 0;
}

/*
input:
8 10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7

output:
0 1 2 3 4 5 6 7

 */
