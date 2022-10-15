//
// Created by SAYON DEEP on 17-08-2022.
//https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
public:
    int lps(string s)
    {
        // Your code goes here
        int n = s.length();
        vector<int> kmp(n,0);

        int i=1,len=0; //len is how much has been matched from 0 for the present i // len is kmp[i-1];
        //len traverses prefix and i traverses the string;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                len++;
                kmp[i++]=len;

            }
            else
            {
                if(len>0)
                {
                    len = kmp[len-1];  //kmp[len-1] knows till what was already matched from beginning.
                    //len goes back to where there could be chance of matching
                }
                else
                    kmp[i++]=0;
            }
        }

        return kmp[n-1];

    }
};

//{ Driver Code Starts.

int main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}
