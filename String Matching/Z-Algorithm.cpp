//
// Created by SAYON DEEP on 14-08-2022.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> z_functionn(string &s) //O(n^2)
{
    int n = s.length();
    vector<int> z(n);
    z[0]=0;
    for (int i = 1; i < n; ++i)
    {
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
            z[i]++;
    }
    return z;

}

vector<int> z_function(string &s) //https://www.youtube.com/watch?v=QlwzsWs0oyc&t=1159s
{
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[0+(i - l)]); //jump from 0
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) // if z-box increases
            l = i, r = i + z[i] - 1;
    }
    return z;

}


vector<int> zalgo(string &text,string &pat)
{
    string str = pat + "$" + text;

    return z_functionn(str);
    //return z_function(str);
    /*vector<int> z(str.length());
    z[0]=0;
    int l=0,r=0;

    for(int k=1;k<str.length();k++)
    {
       if(k>r) //inside z-box
       {

       }
       else //outside z-box
       {

       }
    }*/

}

int main()
{
    string text = "xabcabzabc";
    string pattern = "abc";

    vector<int> z = zalgo(text,pattern);

    for(int e:z)
        cout<<e<<" ";

    cout<<endl;

    return 0;
}