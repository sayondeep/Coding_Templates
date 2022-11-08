//
// Created by SAYON DEEP on 08-11-2022.
//
#include <bits/stdc++.h>
using namespace std;
class segtree {

    vector<int> seg;

public:
    segtree(int n)
    {
        seg.resize(4*n);
    }

    void build(int index, int low, int high,vector<int>& arr)
    {
        if (low == high) {
            seg[index] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);

        seg[index] = seg[2 * index + 1]^seg[2 * index + 2];
    }

    int query(int index, int low, int high, int l, int r)
    {
        //outside range = l>high || r<low
        if (l > high || r < low)
            return 0;

        if (low >= l && high <= r)
            return seg[index];

        int mid = low + (high - low) / 2;

        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);
        return left ^ right;
    }

    void update(int index, int low, int high, int i, int e)
    {
        if (low == high) {
            seg[index] = e;
            return;
        }

        int mid = low + (high - low) / 2;

        if (i <= mid)
            update(2 * index + 1, low, mid, i, e);
        else
            update(2 * index + 2, mid + 1, high, i, e);

        seg[index] = seg[2 * index + 1]^ seg[2 * index + 2];
    }
};
int main()
{
    string str;
    cin>>str;

    int n=str.length();

    vector<int>freq(26);
    for(int i=0;i<n;i++)
    {
        int index = str[i]-'a';
        freq[index]++;
    }

    segtree* sg = new segtree(26);
    sg->build(0,0,n-1,freq);

    int q;
    cin>>q;

    while(q--)
    {
        int t;
        int arg1;
        int arg2;
        cin>>t>>arg1>>arg2;

        if(t==1)
        {
            cout<<sg->query(0,0,n-1,arg1-1,arg2-1);
        }
        else if(t==2)
        {

        }
    }

    return 0;
}