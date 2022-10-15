//
// Created by SAYON DEEP on 30-06-2022.
//https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h>
using namespace std;
bool relax(vector<int> &edge,vector<int>&dist)
{
    int src = edge[0];
    int dest=edge[1];
    int w = edge[2];
    bool isupdated = false;
    if(dist[src]!=1e9 && dist[dest]>dist[src]+w) //1e9 because question demanded no path to return 1e9
    {
        dist[dest]=dist[src]+w;
        isupdated = true;

    }


    return isupdated;


}


int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.

    vector<int>dist(n+1,1e9);//1e9 because question demanded no path to return 1e9

    dist[src]=0;

    for(int i=1;i<n;i++)
    {
        for(vector<int> e:edges)
        {
            relax(e,dist);
        }
    }

    for(vector<int> e:edges)
    {
        if(relax(e,dist))
        {
            dist[e[1]] = 1000000000;
        }
    }


    return dist[dest];


}
int main()
{
    return 0;
}
