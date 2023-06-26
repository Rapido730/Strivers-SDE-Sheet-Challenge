// Problem Link : https: // leetcode.com/problems/combination-sum-ii/

class Solution
{
public:
    void solve(int ind, int target, vector<int> &cand, vector<vector<int>> &ans, vector<int> &inst)
    {

        if (target == 0)
        {
            ans.push_back(inst);
            return;
        }

        for (int i = ind; i < cand.size(); i++)
        {

            if (i > ind && cand[i] == cand[i - 1])
                continue;

            if (cand[i] > target)
                break;

            inst.push_back(cand[i]);
            solve(i + 1, target - cand[i], cand, ans, inst);
            inst.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> inst;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, ans, inst);
        return ans;
    }
};