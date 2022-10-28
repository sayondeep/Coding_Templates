//
// Created by SAYON DEEP on 27-10-2022.
//
#include <bits/stdc++.h>
using namespace std;

vector<int>is_prime(100000+10,1);




int prime_permutation(int n)
{
    string str = to_string(n);

    sort(str.begin(),str.end());

    cout<<str<<endl;

    do
    {
        int num = stoi(str);
        cout<<num<<" is ";
        if(is_prime[num])
            cout<<"prime \n";
        else
            cout<<"not prime \n";

    }while(next_permutation(str.begin(),str.end()));


    return 0;
}

int main()
{
    int n;
    cin>>n;
    is_prime[1]=0;

    for(int i=2;i<100000+10;i++)
    {
        if(is_prime[i])
        {
            for(int j=2*i;j<100000+10;j+=i)
                is_prime[j]=0;
        }
    }

    prime_permutation(n);


    return 0;

}