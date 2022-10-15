//
// Created by SAYON DEEP on 14-09-2022.
//
#include <bits/stdc++.h>
using namespace std;

class Seg_Tree
{
    vector<int>seg,lazy;

public:
    Seg_Tree(int n)
    {
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int index,int low,int high,vector<int>&arr)
    {
        if(low==high)
        {
            seg[index]= arr[low];
            return;
        }

        int mid = low + (high-low)/2;

        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);

        seg[index] = seg[2*index+1]+seg[2*index+2];

    }

    void update(int index,int low,int high,int l,int r,int val,vector<int>&arr)
    {
        //update if pending and propagate down
        if(lazy[index]!=0)
        {
            seg[index] = seg[index]+(high-low+1)*lazy[index];
            if(low!=high) //propagate
            {
                lazy[2*index+1] +=lazy[index];
                lazy[2*index+2]+= lazy[index];
            }
            lazy[index]=0;
        }

        if(l>high || r<low)
            return;
        if(l<=low && high<=r)
        {
            seg[index]+= (high-low+1)* val; //update

            if(low!=high) //propagate
            {
                lazy[2*index+1]+=val;
                lazy[2*index+2]+=val;
            }

            return;
        }

        int mid = low+ (high-low)/2;
        update(2*index+1,low,mid,l,r,val,arr);
        update(2*index+2,mid+1,high,l,r,val,arr);

        seg[index] = seg[2*index+1]+seg[2*index+2];

    }

    int query(int index,int low,int high,int l,int r)
    {
        if(lazy[index]!=0)
        {
            seg[index] = seg[index]+(high-low+1)*lazy[index];
            if(low!=high)
            {
                lazy[2*index+1] +=lazy[index];
                lazy[2*index+2]+= lazy[index];
            }
            lazy[index]=0;
        }

        if(l>high || r<low)
            return 0;

        if(l<=low && high<=r)
        {
            return seg[index];
        }

        int mid = low + (high-low)/2;

        int left = query(2*index+1,low,mid,l,r);
        int right = query(2*index+2,mid+1,high,l,r);

        return left+right;
    }


};


int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Seg_Tree* st = new Seg_Tree(n);
    st->build(0,0,n-1,arr);

    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int l,r,val;
            cin>>l>>r>>val;
            st->update(0,0,n-1,l,r,val,arr);
        }
        if(type==2)
        {
            int l,r;
            cin>>l>>r;
            cout<< st->query(0,0,n-1,l,r)<<endl;
        }
    }


    return 0;
}

/*
5
 1 4 6 3 9
 6
 2 1 3
 1 1 3 2
 2 1 3
 2 0 1
 1 0 1 -2
 2 0 1
 */