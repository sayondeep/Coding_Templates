//
// Created by SAYON DEEP on 20-08-2022.
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

    void build(int index, int low, int high, int arr[]) {
        if (low == high) {
            seg[index] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);

        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }

    int query(int index, int low, int high, int l, int r) {
        //outside range = l>high || r<low
        if (l > high || r < low)
            return INT_MAX;

        if (low >= l && high <= r)
            return seg[index];

        int mid = low + (high - low) / 2;

        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int index, int low, int high, int i, int e, int arr[]) {
        if (low == high) {
            seg[index] = e;
            arr[i] = e;
            return;
        }

        int mid = low + (high - low) / 2;

        if (i <= mid)
            update(2 * index + 1, low, mid, i, e, arr);
        else
            update(2 * index + 2, mid + 1, high, i, e, arr);

        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
};


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    segtree* sg = new segtree(n);
    sg->build(0,0,n-1,arr);

    int q;
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        cout<<sg->query(0,0,n-1,l,r)<<endl;

    }
    return 0;
}
