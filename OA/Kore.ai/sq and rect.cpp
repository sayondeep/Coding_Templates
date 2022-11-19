//
// Created by SAYON DEEP on 19-11-2022.
//

#include <bits/stdc++.h>
using namespace std;

int square_rect (int n, vector<vector<int>>&arr)
{

    map<int,int> freq;
    for(vector<int> v:arr)
    {
        freq[v[0]]=v[1];
    }
    map<int,int> freq_2;

    for (auto i:freq)
    {
        if (freq[i.first] >= 2)
            freq_2[i.first] = freq[i.first];
    }

    vector<int> arr1;
    for (auto i:freq_2)
        arr1.push_back((i.first) * ((freq_2[(i.first)]/2)*2));
    sort(arr1.rbegin(), arr1.rend());


    for(int e:arr1)
        cout<<e<<" ";
    cout<<endl;

    int summ = 0;
    for (int i:arr1)
        summ += i;

    // Print the sum

    for(int i=0;i<=((arr1.size()/4)*4);i++)
    cout << summ;

    return summ;

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