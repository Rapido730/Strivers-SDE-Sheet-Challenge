// Problem Link :  https: // leetcode.com/problems/subsets-ii/description/

class Solution
{
public:
    void solve(vector<int> arr, int ind, int N, vector<vector<int>> &ans, vector<int> &inst)
    {

        ans.push_back(inst);
        for (int i = ind; i < arr.size(); i++)
        {
            if (i != ind && arr[i] == arr[i - 1])
            {
                continue;
            }

            inst.push_back(arr[i]);
            solve(arr, i + 1, N, ans, inst);
            inst.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> inst;
        sort(nums.begin(), nums.end());
        solve(nums, 0, nums.size(), ans, inst);
        return ans;
    }
};