//  Problem Link : https : // www.codingninjas.com/codestudio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int maxi = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxi = max((i + 1), maxi);
        }
        else
        {
            if (mp.find(sum) != mp.end())
            {
                maxi = max(maxi, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }

    return maxi;
}