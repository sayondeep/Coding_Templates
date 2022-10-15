#include <bits/stdc++.h>
using namespace std;

void heapify(int i, vector<int>&arr)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    int n = arr.size();

    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest  = right;

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(largest,arr);
    }
}

void build_heap(vector<int>&arr)
{
    int n = arr.size();

    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(i,arr);
    }
}

int main()
{
    vector<int> arr;
    arr = {12,56,23,78,25,45,98,1,4,19};

    build_heap(arr);

    for(int x:arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
