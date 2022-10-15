//
// Created by SAYON DEEP on 14-08-2022.
//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void shortest_distance(vector<vector<int>>&matrix)
    {
        // Code here

        int n = matrix.size();


        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j]==-1)
                    matrix[i][j]=1e9;
            }
        }

        vector<vector<int>> prev = matrix;

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j]= min(prev[i][j],prev[i][k]+prev[k][j]);
                }
            }

            prev = matrix;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j]>=1e9)
                    matrix[i][j]=-1;
            }
        }
    }
};



int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>>matrix(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}