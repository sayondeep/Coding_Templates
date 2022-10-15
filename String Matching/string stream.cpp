//
// Created by SAYON DEEP on 01-09-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin,str);

    stringstream ss(str);

     string word;
     while(getline(ss,word,','))
     {
         cout<<word<<endl;
     }
}
