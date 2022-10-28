//
// Created by SAYON DEEP on 24-10-2022.
//
#include <bits/stdc++.h>
using namespace std;

bool isvalidminute(int a, int b){
    int x = 10*a+b;
    if(x>=0 and x<60) return 1;
    return 0;
}

bool isvalidhour(int a, int b){
    int x = 10*a+b;
    if(x>=0 and x<24) return 1;
    return 0;
}

int solution(int A, int B, int C, int D){
    vector<int> time;
    int count=0;
    time.push_back(A);
    time.push_back(B);
    time.push_back(C);
    time.push_back(D);
    sort(time.begin(),time.end());

    do{
        if(isvalidminute(time[2],time[3]) and isvalidhour(time[0],time[1])){
            count++;
            cout<<time[0]<<" "<<time[1]<<" "<<time[2]<<" "<<time[3]<<endl;
        }
    }
    while(next_permutation(time.begin(),time.end()));
    return count;
}


int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<solution(a,b,c,d)<<endl;
    return 0;
}