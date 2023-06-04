// Problem Link : codingninjas.com / codestudio / problems / 893046 ? topList = striver - sde - sheet - problems &utm_source = striver &utm_medium = website

#include <bits/stdc++.h>
vector<int>
nextPermutation(vector<int> &permutation, int n)
{

    int k = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
        {
            k = i;
            break;
        }
    }

    if (k == -1)
    {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    // int j = -1;
    for (int i = n - 1; i >= k + 1; i--)
    {
        if (permutation[i] > permutation[k])
        {
            swap(permutation[k], permutation[i]);
            break;
        }
    }

    reverse(permutation.begin() + k + 1, permutation.end());
    return permutation;
}