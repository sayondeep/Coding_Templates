//
// Created by SAYON DEEP on 08-11-2022.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n),dep(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>dep[i];
    }
    int m;
    cin>>m;

    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());

    int i=0,j=0;

    //int time = arr[0];
    int cores=0;
    int max_cores=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            cores++;
            max_cores = max(max_cores,cores);
            i++;
        }
        else
        {
            cores--;
            j++;
        }
    }

    cout<<max_cores<<endl;
    return 0;
}