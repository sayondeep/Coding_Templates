//
// Created by SAYON DEEP on 28-06-2022.
//https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h>
using namespace std;

void call_dfs(int i,vector<int> edges[],vector<int>&visited,stack<int>&st)
{
    visited[i]=1;
    for(int v:edges[i])
    {
        if(visited[v]==0)
            call_dfs(v,edges,visited,st);
    }

    st.push(i);

}


int stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> edge[n];

    for(vector<int>e:edges)
        edge[e[0]].push_back(e[1]);

    vector<int> visited(n,0);
    stack<int>st;



    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            call_dfs(i,edge,visited,st);
    }

    for(int i=0;i<n;i++)
        visited[i]=0;

    vector<int> edgec[n];

    for(vector<int>e:edges)
        edgec[e[1]].push_back(e[0]);

    int comp=0;

    stack<int> st1;
    while(!st.empty())
    {
        int v = st.top();
        st.pop();
        if(visited[v]==0)
        {
            comp++;
            call_dfs(v,edgec,visited,st1);
        }
    }

    return comp;

}
int main()
{
    return 0;
}
