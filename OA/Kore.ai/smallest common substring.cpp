//
// Created by SAYON DEEP on 19-11-2022.
//

#include <bits/stdc++.h>
using namespace std;
int smallest_common_substrings(string &A, string &B) {
    int freq[26] = {0};

    for (char c : A) {
        freq[c - 'a']++;
    }

    int sum = 0;

    for (char c : B) {
        sum += freq[c - 'a'];
    }

    return sum;
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;

    cout<<smallest_common_substrings(str1,str2);
    return 0;
}