//
// Created by SAYON DEEP on 27-06-2022.
//

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

int main()
{
    DSU* set = new DSU(10);

    set->make(10);

    cout<<set->find(9);
    set->_union(8,9);
    cout<<set->find(8);
    set->_union(6,8);
    cout<<set->find(6);

    int c=0;
    for(int i=0;i<10;i++)
    {
        if(set->find(i)==i)
            c++;
    }
    cout<<"\n# of components: "<<c<<endl;
}
