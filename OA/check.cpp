//
// Created by SAYON DEEP on 31-10-2022.
//
#include <bits/stdc++.h>
using namespace std;

class S
{
public:
    int a,b,c;

    S()
    {
        this->a=this->b=this->c=0;
    }

    S(S& other)
    {
        this->a=other.a;

    }

    bool compare(S other)
    {
        return this->a==other.a;
    }
};

int max_val(int i,vector<int>&cell,vector<int> &step)
{
    if(i==0)
        return 0;

    int max_point = INT_MIN;
    for(int j:step)
    {
        if(i-j>=0)
        {
            int point = cell[i]+ max_val(i-j,cell,step);

            max_point = max(max_point,point);
        }
    }

    return max_point;
}

int main()
{

    S first,second;

    //cout<<first.compare(second);

    vector<int>cell={0,-10,100,-20};
    vector<int> step={1,3};

    int n= 4;

    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int max_point = INT_MIN;
        for(int j:step)
        {
            if(i-j>=0)
            {
                int point = cell[i]+ dp[i-j];

                max_point = max(max_point,point);
            }

            dp[i]= max_point;

        }
    }

    cout<<dp[n-1]<<endl;

    cout<<max_val(n-1,cell,step)<<endl;

    for(int i:dp)
        cout<<i<<" ";




    return 0;
}