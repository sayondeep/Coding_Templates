//
// Created by SAYON DEEP on 21-11-2022.
//
#include <bits/stdc++.h>
using namespace std;


bool compare(pair<char,int>&a,pair<char,int>&b)
{
    return a.second>b.second;
}
int decrypt(vector<string>&arr)
{
    int n = arr.size();

    unordered_map<char,int> contr;
    //unordered_map<char,bool>first;
    set<char>first;

    int ans = 0;

    for(string str:arr)
    {
        if(isalpha(str[0]))
            first.insert(str[0]);
        reverse(str.begin(),str.end());

        for(int i=0;i<str.size();i++)
        {
            int val = pow(10,i);
            if(isalpha(str[i]))
                contr[str[i]]+= val;
            else
                ans+= ((str[i]-'0'))*pow(10,i);
        }
    }


    //cout<<"first"<<endl;

    /*for(char e:first)
        cout<<e<<" ";
    cout<<endl;*/

    /*for(pair<char,int> p:contr)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }*/
    int maxi=0;
    char mx='.';
    for(pair<char,int> p:contr)
    {
        if(first.find(p.first)==first.end())
        {
            if(p.second>maxi)
            {
                maxi=p.second;
                mx = p.first;
            }
        }
    }

    if(mx !='.')
    {
        contr.erase(mx);
        //cout<<"removed"<<mx<<endl;

    }

    vector<pair<char,int>> v(contr.begin(),contr.end());
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
    {
        ans+= (i+1)*contr[v[i].first];
    }
    //cout<<ans<<endl;
    //cout<<"running"<<endl;
    return ans;
}

int main()
{

    int n;
    cin>>n;
    vector<string> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<decrypt(arr)<<endl;
    return 0;
}
/*
2
A1A 2AB
3
CB BC BAB
3
A1A3 AAB BD1
 */