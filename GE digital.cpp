#include <bits/stdc++.h>
using namespace std;
//void printDatesAscending(vector<string> arr)
//{
//    // Sort the dates using library
//    // sort function with custom Comparator
//    sort(arr.begin(), arr.end(), myCompare);
//
//    // Loop to print the dates
//    for (int i = 0; i < arr.size(); i++)
//        cout << arr[i] << "\n";
//}

bool comp(vector<int>&a,vector<int>&b)
{
    if(a[2]<b[2] )
        return true;
    else if(a[2]==b[2] && a[1]<b[1])
        return true;
    else if(a[2]==b[2] && a[1]==b[1] && a[0]<b[0])
        return true;


    return false;
}
void printDates(string dates[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << dates[i] << endl;
    }
}
int main()
{
    string dates[] = { "24 Jul 2017", "25 Jul 2017", "11 Jun 1996",
                       "01 Jan 2019", "12 Aug 2005", "01 Jan 1997" };


    int n = sizeof(dates) / sizeof(dates[0]);

    //stringstream ss;
    string mon[] = {"Jan", "Feb", "Mar", "Apr"," May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    unordered_map<string,int> mp;
    mp["Jan"] = 1;
    mp["Feb"] = 2;
    mp["Mar"] = 3;
    mp["Apr"] = 4;
    mp["May"] = 5;
    mp["Jun"] = 6;
    mp["Jul"] = 7;
    mp["Aug"] = 8;
    mp["Sep"] = 9;
    mp["Oct"] = 10;
    mp["Nov"] = 11;
    mp["Dec"] = 12;

    vector<vector<int>>v;
    for(int i=0;i<n;i++)
    {
        stringstream ss(dates[i]);
        string word;
        vector<int>data;
        while(getline(ss,word,' '))
        {

            if(mp.find(word)!=mp.end())
            {
                data.push_back(mp[word]);
            }
            else
            {
                data.push_back(stoi(word));
            }
        }

        v.push_back(data);
    }

    sort(v.begin(),v.end(),comp);

    int i=0;
    for(vector<int> d:v)
    {
        string str="";

        str+= (to_string(d[0])+" "+mon[d[1]-1]+" "+to_string(d[2]));
        dates[i++]=str;
    }

    printDates(dates, n);
}