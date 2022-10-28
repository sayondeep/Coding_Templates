//
// Created by SAYON DEEP on 06-11-2022.
//

#include <bits/stdc++.h>
using namespace std;

int get_m(int x,int y,int mul)
{
    if(x%y==0)
        return x;
    cout<<x<<endl;
    x*=mul;
    //cout<<x<<endl;
    for(int i=0;i<mul;i++)
    {
        cout<<x+i<<endl;
        if((x+i)%y==0)
        {
            return x+i;
        }
    }
    return get_m(x/mul,y,mul*10);
}

int main()
{
    int x,y;
    cin>>x>>y;
    int ans = get_m(x,y,10);
    cout<<"ans:"<<ans<<endl;
    return 0;
}