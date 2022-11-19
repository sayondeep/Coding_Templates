//
// Created by SAYON DEEP on 19-11-2022.
//

#include <bits/stdc++.h>
using namespace std;

int square_rect (int n, vector<vector<int>>&arr)
{
    int ans=0;
    vector<int> arr1;
    for(vector<int> v:arr)
    {
        if (v[1] >= 2)
        {
            ans+= (v[0]*((v[1]/4)*4));
            v[1]=v[1]%4;
            if (v[1] >= 2)
            {

                arr1.push_back(v[0] * (v[1]/2)*2);
            }

        }
    }

    sort(arr1.rbegin(), arr1.rend());

    int sz = arr1.size();

    if(sz&1)
        sz--;

    for (int i=0;i<sz;i++)
        ans += arr1[i];

    cout << ans<<endl;

    return ans;

}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> arr(n,vector<int>(2));

    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
    }

    cout<<square_rect(n,arr)<<endl;

    return 0;
}
/*
4
5 6
3 2
4 3
6 1
 */