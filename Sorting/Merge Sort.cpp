//
// Created by SAYON DEEP on 11-07-2022.
//
#include <bits/stdc++.h>
using namespace std;


void merge(vector<int>&v,int beg,int mid,int end)
{
    int left = beg;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=end)
    {
        if(v[left]<v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(v[left]);
        left++;
    }
    while(right<=end)
    {
        temp.push_back(v[right]);
        right++;
    }
    int k=0;
    for(int i=beg;i<=end;i++)
    {
        v[i]= temp[k++];
    }
}


void merge_sort(vector<int>&v,int beg,int end)
{


    if(beg<end)
    {
        int mid = (beg+end)/2;
        merge_sort(v,beg,mid);
        merge_sort(v,mid+1,end);
        merge(v,beg,mid,end);
    }

}

int main()
{
    vector<int> v={12,1,45,67,2,34,90,4,16,12,12,12,13,78,78,99};
    int n= v.size();
    merge_sort(v,0,n-1);


    for(int e : v)
        cout<<e<<" ";


    return 0;
}