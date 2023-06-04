// Problem Link : https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_8230694?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
long long maxSubarraySum(int nums[], int n)
{
    long long sum = 0;
    long long maxi = 0;
    for (int r = 0; r < n; r++)
    {
        sum += nums[r];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}