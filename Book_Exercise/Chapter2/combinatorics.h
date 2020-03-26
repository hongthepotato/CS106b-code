/* File: combinatorics.h
   --------------------
   This file contains two frequently used functions in combi. maths.*/
#ifndef _combinatorics_h
#define _combinatorics_h


/* Function permutation
   Usage: permutation(n, k);
   -------------------------
   The permutation function takes two integer n and k, calculate the possible ways
   of picking K items out of total n items and the order matters.
   For example, pick out a penny than a dime is different from dime followed by a penny.
   k cannot be larger than n or error message will pop up. Negative n or k are not allowed. */
int permtation(int n, int k);


/*  Function combination
    Usgae: combination(n,k)
    -----------------------
    The combination has the similar function as the permutation function that takes into
    two integers n and k and calculate the possible ways of picking k items out of total n items.
    Different from permutation function, combination function doesn't care about the order of which
    of the picked items comes first.
    Of course, negative integer or cases that k larger than n are not allowed.*/
int combination(int n, int k);




#endif