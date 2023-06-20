// Problem Link : https://www.codingninjas.com/studio/problems/3sum_8230739?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> nums, int n, int K)
{
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int l = i + 1;
        int r = n - 1;
        int tar = K - nums[i];
        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum == tar)
            {
                ans.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
            }
            else if (sum > tar)
            {
                r--;
            }
            else
            {
                l++;
            }

            while (r < n - 1 && l < r && nums[r] == nums[r + 1])
            {
                r--;
            }

            while (l > i + 1 && l < r && nums[l] == nums[l - 1])
            {
                l++;
            }
        }
    }

    return ans;
}