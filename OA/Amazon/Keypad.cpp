//
// Created by SAYON DEEP on 07-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()

{
    string str;
    cin>>str;

    vector<int>freq(26);

    for(char ch: str)
    {
        int index = ch - 'a';
        freq[index]++;
    }

    sort(freq.rbegin(),freq.rend());

    /*for(int i:freq)
        cout<<i<<" ";*/

    int total_press=0;
    for(int i=0;i<9;i++)
    {
        total_press+=(freq[i]*1);
    }
    for(int i=9;i<18;i++)
    {
        total_press+=(freq[i]*2);
    }
    for(int i=18;i<26;i++)
    {
        total_press+=(freq[i]*3);
    }

    cout<<total_press<<endl;

    return 0;
}