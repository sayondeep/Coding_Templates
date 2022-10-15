//
// Created by SAYON DEEP on 14-10-2022.
//

#include "Shapes.h"
#include <bits/stdc++.h>
using namespace std;

int Shapes::volume() {
    return length*breadth;
}

Shapes::Shapes(int length,int breadth) {
    this->length = length;
    this->breadth = breadth;
}
