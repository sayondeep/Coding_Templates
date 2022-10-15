//
// Created by SAYON DEEP on 26-06-2022.
//

#include<bits/stdc++.h>
using namespace std;

class fenwick
{
    vector<int> f;
public:
    fenwick(int size)
    {
        f.resize(size+1,0);
    }

    void update(int idx, int x)
    {
        idx++;
        int n = f.size();
        while(idx<n)
        {
            f[idx] += x;

            idx = idx + (idx & (-idx)); // adds 1 to right most set bit
        }
    }

    int sum(int idx)
    {
        idx++;
        int ans = 0;
        while(idx>0)
        {
            ans += f[idx];
            idx = idx-(idx & (-idx)); // unsets the right most set bit to go to parent(Coding minutes)
        }

        return ans;


    }

};



int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};

    fenwick* tree = new fenwick(arr.size());

    int n = arr.size();

    for(int i=0;i<n;i++)
    {
        tree->update(i,arr[i]);
    }

    cout<< tree->sum(3)<<endl;
    cout<<tree->sum(n-1)<<endl;


}