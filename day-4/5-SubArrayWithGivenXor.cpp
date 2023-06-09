// Problem Link : https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_8230830?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> mp;
    int xorr = 0;
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        xorr ^= arr[i];

        if (xorr == x)
        {
            count++;
        }

        if (mp.find(xorr ^ x) != mp.end())
        {
            count += mp[xorr ^ x];
        }

        mp[xorr]++;
    }

    return count;
}