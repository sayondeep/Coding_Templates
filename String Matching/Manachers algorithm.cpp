//
// Created by SAYON DEEP on 26-10-2022.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> manacher(string str)
{
    int n = str.length();

    vector<int>lps(n,0);

    int c=0,r=0; // centre and far sight

    for(int i=1;i<n-1;i++)
    {
        if(i<r)
        {
            int mirror_index = c - (i-c); // index of element across mirror to take value
            lps[i] = min(r-i,lps[mirror_index]);
        }

        while(str[i+lps[i]+1]==str[i-lps[i]-1])     //Brute force
            lps[i]++;


        if(i+lps[i]>r)
        {
            c=i;        //update mirror index
            r=i+lps[i]; //update far sightedness
        }
    }

    return lps;
}
int main()
{
    string str;

    cin>>str;
    //str="pqpqpqp";
    string s="";
    s+='@';
    for(int i=0;i<str.length();i++)
    {
        s += ("#");
        s+= str[i];
    }

    s+= ("#$");

    cout<<s<<endl;

    vector<int>lps = manacher(s);

    for(int i=0;i<lps.size();i++)
    {
        cout<<lps[i]<<" ";
    }
    cout<<endl;

    return *max_element(lps.begin(),lps.end());
}
