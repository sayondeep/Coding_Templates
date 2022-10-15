//
// Created by SAYON DEEP on 11-07-2022.
//

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&v,int beg,int end)
{

    int pivot = v[end];
    int l = beg-1;

    for(int i=beg;i<=end;i++)
    {
        if (v[i] <= pivot)
        {
            l++;
            swap(v[l], v[i]);
        }


    }
    //swap(v[l + 1], v[end]);
    return l ;
}

void quick_sort(vector<int>&v,int beg,int end)
{

    if(beg<end)
    {
        int p = partition(v,beg,end);
        quick_sort(v,beg,p-1);
        quick_sort(v,p+1,end);
    }
}

int main()
{
    vector<int> v={12,1,45,67,2,34,90,4,16,12,12,12,13,78,78,99};
    int n= v.size();
    quick_sort(v,0,n-1);


    for(int e : v)
        cout<<e<<" ";
    return 0;
}
