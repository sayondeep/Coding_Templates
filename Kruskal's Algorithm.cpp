//
// Created by SAYON DEEP on 28-06-2022.
//
//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118511/offering/1381545
#include <bits/stdc++.h>
using namespace std;

class DSU {


    int *parent,*size;


public:

    DSU(int v)
    {
        parent = new int[v];
        size = new int[v];
    }

    void make(int v)
    {
        for(int i=0;i<v;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int find(int v)
    {
        if (parent[v] == v)
            return v;

        return parent[v] = find(parent[v]); //path compression to optimize parent search
    }

    void _union(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return;


        if (size[a] < size[b]) // rank to optimize node joining
            swap(a, b);  //size is equivalent to size.


        parent[b] = a;

        size[a] += size[b]; //because size of larger size increased and anyways the
        //smaller ones parent is larger node
    }
};

bool compare(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    /*
      Don't write main().
      Don't read input, it is passed as function argument.
      No need to print anything.
      Taking input and printing output is handled automatically.
    */
    sort(edges.begin(),edges.end(),compare);

    DSU *set = new DSU(n);
    set->make(n);

    int cost = 0;

    for(int i=0;i<n;i++)
    {
        if(set->find(edges[i][0])!=set->find(edges[i][1]))
        {
            cost+= edges[i][2];

            set->_union(edges[i][0],edges[i][1]);
        }

    }

    return cost;

}

int main()
{
    return 0;
}
