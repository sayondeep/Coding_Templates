//
// Created by SAYON DEEP on 19-10-2022.
//
#include <bits/stdc++.h>
using namespace std;

int find(vector<int>&parent,int a)
{
    if(parent[a]==a)
        return a;

    return parent[a]=find(parent,parent[a]);
}

void _union(vector<int>&parent,vector<int>&size,int a,int b)
{
    a = find(parent,a);
    b = find(parent,b);

    if(a==b)
        return;

    if(size[a]<size[b])
    {
        swap(a,b);
    }


    parent[b]=a;
    size[a]+= size[b];

}

int main()
{
    int n,m;
    cin>>n>>m;

   vector<int>from(m),to(m),broken(m,0);

   for(int i=0;i<m;i++)
   {
       cin>>from[i]>>to[i];
   }

   int q;
   cin>>q;
   vector<int>query(q);
   for(int i=0;i<q;i++)
   {
        cin>>query[i];
        query[i]--;

        broken[query[i]]=1;
   }
   vector<int>parent(n+1),size(n+1,1);
   for(int i=0;i<=n;i++)
       parent[i]=i;
   for(int i=0;i<m;i++)
   {
       if(broken[i]==0)
           _union(parent,size,from[i],to[i]);
   }
   int max_unity = *max_element(size.begin(),size.end());
   vector<int>ans(q);
   for(int i=q-1;i>=0;i--)
   {
       ans[i]=max_unity;
       _union(parent,size,from[query[i]],to[query[i]]);
       max_unity = max({max_unity,size[from[query[i]]],size[to[query[i]]]});

   }

   for(int i=0;i<q;i++)
   {
       cout<<ans[i]<<endl;
   }

   return 0;

}

/*
5
4
1 3 3 5
3 2 4 1
2
1 3
*/
