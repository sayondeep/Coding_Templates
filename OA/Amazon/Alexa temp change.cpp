//
// Created by SAYON DEEP on 07-11-2022.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    vector<long long int> temp(n);
    for(int i=0;i<n;i++)
    {
        cin>>temp[i];
    }

    long long int total_sum = accumulate(temp.begin(),temp.end(),0);
    long long int max_change = max(temp[0],total_sum);
    int now_sum = temp[0];
    for(int i=1;i<n;i++)
    {
        long long int right_sum = total_sum-now_sum;
        now_sum+= temp[i];
        long long int left_sum = now_sum;
        long long int curr_max = max(left_sum,right_sum);
        max_change = max(max_change,curr_max);
    }

    cout<<max_change<<endl;


    return 0;
}