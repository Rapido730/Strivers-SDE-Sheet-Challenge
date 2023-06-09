// Problem Link : https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence_8230708?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    unordered_set<int> hash_set;
    for (int i : arr)
    {
        hash_set.insert(i);
    }
    int maxi = 0;
    for (int i : arr)
    {
        if (!hash_set.count(i - 1))
        {

            int current_num = i;
            int count = 1;

            while (hash_set.count(current_num + 1))
            {
                count++;
                current_num++;
            }
            maxi = max(maxi, count);
        }
    }

    return maxi;
}