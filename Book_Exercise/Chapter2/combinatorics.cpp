/**
 *  File: combinatorics.cpp
 *  -------------------
 *  This file implemented function is combinatorics.h interface.
*/
#include <iostream>
#include "combinatorics.h"

using namespace std;

int permutation(int n, int k){
    if (n <= 0 || k <= 0 || k > n){
        cerr << "Cannot have negtive integers nor larger k in permutation." << endl;
        exit(1);
    }
    int product = 1;
    for (int i = 1; i <= k; i++)
    {
        product = product * n;
        n -= 1;
    }
    return product;
}

int combination(int n, int k){
    if (n <= 0 || k <= 0 || k > n){
        cerr << "Cannot have negtive integers nor larger k in permutation." << endl;
        exit(1);
    }
    int product = 1;
    for (int i = 1; i <= k; ++i){
        product = product * n;
        n -= 1;
    }
    int fact = 1;
    for (int i = 1; i <= k; ++i){
        fact = fact * i;
    }
    return product / fact;
}