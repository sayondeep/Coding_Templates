//
// Created by SAYON DEEP on 28-06-2022.
//https://practice.geeksforgeeks.org/problems/articulation-point-1/0/#
#include <bits/stdc++.h>
using namespace std;

void call_dfs(int i,int p,vector<int> edges[],vector<int>&visited,vector<int>&disc,vector<int>&low_disc,int &timer,unordered_set<int>&ans)
{
    visited[i]=1;
    disc[i]=timer;
    low_disc[i]=timer;
    timer++;


    int child = 0;
    for(int v:edges[i])
    {

        if(visited[v]==0)
        {
            call_dfs(v,i,edges,visited,disc,low_disc,timer,ans);
            //update lowest discovery time due to updation of childs lowest discovery time
            low_disc[i]= min(low_disc[i],low_disc[v]);
            //check articulation point
            if(low_disc[v]>=disc[i] && p != -1) //p!=-1 for star like graph where node is root then leaves will always T for cond 1
            {
                ans.insert(i);
            }

            child++;
        }


        else if(v!=p) // Back edge check
        {
            low_disc[i]= min(low_disc[i],disc[v]);
        }
    }

    if(p==-1 && child>1)
        ans.insert(i);
}


vector<int> articulationPoints(int n, vector<int>edge[])
{

    vector<int> disc(n),low_disc(n),visited(n,0);
    int timer=0;
    unordered_set<int> ans;
    for(int i=0;i<n;i++)
    {
        low_disc[i]=-1;
        disc[i]=-1;
        if(visited[i]==0)
            call_dfs(i,-1,edge,visited,disc,low_disc,timer,ans);
    }


    vector<int> req;

    for(int x:ans)
        req.push_back(x);

    if(req.size()==0)
        req.push_back(-1);

    sort(req.begin(),req.end());


    return req;
}
int main()
{
    return 0;
}