//
// Created by SAYON DEEP on 23-07-2022.
//https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209
// Stack class.
#include <bits/stdc++.h>
using namespace std;
class Stack
        {

    vector<int> v;
    int max_size;


public:

    Stack(int capacity)
    {
        // Write your code here.
        max_size=capacity;

    }

    void push(int num)
    {
        // Write your code here.

        v.push_back(num);
    }

    int pop()
    {
        // Write your code here.
        if(v.size()>0)
        {
            int top = v.back();
            v.pop_back();
            return top;
        }
        else
            return -1;
    }

    int top()
    {
        // Write your code here.
        if(v.size()>0)
            return v.back();

        else
            return -1;


    }

    int isEmpty()
    {
        // Write your code here.
        return v.size()==0;

    }

    int isFull()
    {
        // Write your code here.

        return v.size()==max_size;
    }

};

int main()
{
    return 0;
}
