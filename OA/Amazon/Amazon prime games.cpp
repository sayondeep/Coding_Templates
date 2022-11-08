//
// Created by SAYON DEEP on 08-11-2022.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>power(n);
    for(int i=0;i<n;i++)
        cin>>power[i];
    int armour;
    cin>>armour;
    int loss=1;
    int max_loss=0;
    for(int i=0;i<n;i++)
    {
        loss+=power[i];
        max_loss = max(max_loss,power[i]);

    }
    armour = min(armour,max_loss);
    int ans = loss-armour;

    cout<<ans<<endl;

    return 0;
}