//
// Created by SAYON DEEP on 26-06-2022.
//

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

int check(int x)
{
    return arr[x] >= arr[0];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int lo = 0;
    int hi = n - 1;
    int ans = 0; //based on what to return when else block not called at all

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (check(mid))
        {
            lo = mid + 1;
        }
        else
        {
            ans = mid; //store position of 1st NO
            hi = mid - 1;

        }
    }
    cout << ans << endl;
}
