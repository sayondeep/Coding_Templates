//
// Created by SAYON DEEP on 13-07-2022.
//https://leetcode.com/problems/n-queens/submissions/
#include <bits/stdc++.h>
using namespace std;

bool is_valid(int row,int col,vector<string> &board,int &n)
{
    int crow = row,ccol=col;
    while(crow>=0 && ccol>=0)
    {
        if(board[crow][ccol]=='Q')
            return false;

        crow--;ccol--;
    }
    crow = row,ccol=col;
    while(crow>=0 && crow<n && ccol>=0)
    {
        if(board[crow][ccol]=='Q')
            return false;
        crow++;
        ccol--;
    }
    crow = row,ccol=col;
    while(ccol>=0)
    {
        if(board[crow][ccol]=='Q')
            return false;
        ccol--;
    }

    return true;

}

void place_queen(int col,vector<string> &board,int &n,vector<vector<string>> &ans)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }

    for(int row =0;row<n;row++)
    {
        if(is_valid(row,col,board,n))
        {
            board[row][col]='Q';
            place_queen(col+1,board,n,ans);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    string s(n,'.');
    vector<string> board;

    for(int i=0;i<n;i++)
        board.push_back(s);

    place_queen(0,board,n,ans);


    return ans;
}

int main()
{
    return 0;
}