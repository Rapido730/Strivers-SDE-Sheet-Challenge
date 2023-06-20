// Problem Link :  https: // leetcode.com/problems/max-consecutive-ones/description/

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                count++;
                maxi = max(maxi, count);
            }
            else if (nums[i] == 0)
            {
                count = 0;
            }
        }

        return maxi;
    }
};