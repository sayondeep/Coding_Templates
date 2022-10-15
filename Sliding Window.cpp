//
// Created by SAYON DEEP on 07-07-2022.
//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376574
#include<bits/stdc++.h>
using namespace std;

vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
        int n = arr.size();
      int tail=0,head=-1;
      int ans= 0;
      int smallest = INT_MAX;
      while(tail<n)
      {
          while(head+1<n )
          {
              head++;
              mp[arr[head]]++;

          }

          smallest = min(smallest,head-tail+1);  //check on window

          if(head>=tail) // shrink window
          {
              if(mp[arr[tail]]>0)
                  mp[arr[tail]]--;
              else
                  mp.erase(arr[tail]);

              tail++;

          }
          else
          {
              tail++;
              head++;
          }
      }


      return ans;
}

int main()
{
    return 0;
}
