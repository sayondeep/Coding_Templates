 //
// Created by SAYON DEEP on 04-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{

        int n;
        cin>>n;
        vector<int>price(n);

        for(int i=0;i<n;i++)
        {
            cin>>price[i];
        }

        vector<int>suff_avg(n);
        int j=1;
        long long sum = 0;

        for(int i=n-1;i>=0;i--)
        {
            sum+= price[i];
            suff_avg[i] = sum/j;

            j++;
        }

        /*for(int i:suff_avg)
            cout<<i<<" ";
        cout<<endl;*/
        sum=0;
        j=1;
        int pref_avg;
        int min_diff = INT_MAX;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            sum+= price[i];
            pref_avg = sum/j;
            j++;

            int curr_diff = abs(pref_avg-suff_avg[i+1]);
            //cout<<curr_diff<<" ";
            if(curr_diff<min_diff)
            {
                ans=i;
                min_diff=curr_diff;
            }

        }

        cout<<ans+1<<endl;

    return 0;
}