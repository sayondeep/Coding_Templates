//
// Created by SAYON DEEP on 23-06-2022.
//

#include<bits/stdc++.h>
using namespace std;

void call_bfs(int i,vector<int> edges[],vector<int>&visited)
{
    visited[i]=1;
    queue<int> q;
    q.push(i);

    while(!q.empty())
    {
        int node = q.front();
        cout<<node<<" ";
        q.pop();

        for(int v:edges[node])
        {
            if(visited[v]==0)
            {
                visited[v]=1;
                q.push(v);
            }
        }
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