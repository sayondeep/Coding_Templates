//
// Created by SAYON DEEP on 21-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

bool check(char ch)
{
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

vector<int> has_Vowel(vector<string>&arr,vector<string>&query)
{
    int n= arr.size();
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        int sz = arr[i].length();
        if(check(arr[i][0])&&check(arr[i][sz-1]))
            v[i]=1;
        else
            v[i]=0;
    }

    for(int e:v)
        cout<<e<<" ";
    cout<<endl;

    vector<int>pref(n);
    pref[0]=v[0];
    for(int i=1;i<n;i++)
        pref[i]= pref[i-1]+v[i];

    for(int e:pref)
        cout<<e<<" ";
    cout<<endl;
    vector<int>ans;

    for(string str:query)
    {
        int l = str[0]-'0';
        int r = str[2]-'0';
        l--;r--;
        int a;
        if(l-1>=0)
            a = pref[r]-pref[l-1];
        else
            a = pref[r];
        ans.push_back(a);
    }

    return ans;


}

int main()
{
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int q;
    cin>>q;
    vector<string>query(q);
    for(int i=0;i<q;i++)
        cin>>query[i];
    vector<int>ans = has_Vowel(arr,query);

    for(int i:ans)
        cout<<i<<" ";

    return 0;
}

/*
5
aba
bcb
ece
aa
e
3
1-3
2-5
2-2
*/
/*
3
yy
u
oe
2
1-2
2-3
*/
/*
5
aab
a
bcd
awe
bbbbbu
2
2-3
4-5
*/