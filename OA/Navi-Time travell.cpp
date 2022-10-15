//
// Created by SAYON DEEP on 14-10-2022.
//
#include <bits/stdc++.h>
using namespace std;

void call_dfs(int i,vector<int> edges[],vector<int>&visited,unordered_map<int,string>&idname)
{
    visited[i]=1;
    cout<<idname[i]<<endl;
    //cout<<i<<" ";

    for(int v:edges[i])
    {
        if(visited[v]==0)
            call_dfs(v,edges,visited,idname);
    }
}

int main()
{
    int ed;
    cin>>ed;
    vector<vector<int>> edge;

    int id=0;

    unordered_map<string,int>nameid;
    unordered_map<int,string>idname;

    while(ed--)
    {
        string src,dest;
        cin>>src>>dest;
        if(nameid.find(src)==nameid.end())
        {
            nameid[src]=id;
            idname[id]=src;
            id++;
        }
        if(nameid.find(dest)==nameid.end())
        {
            nameid[dest]=id;
            idname[id]=dest;
            id++;
        }
        vector<int>e;
        e.push_back(nameid[src]);
        e.push_back(nameid[dest]);
        edge.push_back(e);
        //cout<<e[0]<<" "<<e[1]<<endl;
    }

    string source;
    cin>>source;

    int n = nameid.size();

    vector<int>edges[n];

    for(vector<int> e:edge)
    {
        edges[e[0]].push_back(e[1]);
    }

//    for(int i=0;i<n;i++)
//    {
//        for(int v:edges[i])
//            cout<<v<<" ";
//
//        cout<<endl;
//    }

//    for(pair<int,string> p:idname)
//    {
//        cout<<p.first<<" "<<p.second<<endl;
//
//    }
    vector<int>visited(n,0);
    call_dfs(nameid[source],edges,visited,idname);

}
/*
5
Bangalore Hyderabad
Bangalore Chennai
Hyderabad Mumbai
Hyderabad Delhi
Chennai Kerala
Bangalore
 */