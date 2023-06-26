// Problem Link : https://www.codingninjas.com/studio/problems/return-subsets-sum-to-k_8230706?challengeSlug=striver-sde-challenge&leftPanelTab=0

void solve(int ind, int target, vector<int> cand, vector<vector<int>> &ans, vector<int> &inst)
{
    if (ind >= cand.size())
    {
        if (target == 0)
        {
            ans.push_back(inst);
        }
        return;
    }

    inst.push_back(cand[ind]);
    solve(ind + 1, target - cand[ind], cand, ans, inst);
    inst.pop_back();

    solve(ind + 1, target, cand, ans, inst);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> cand, int n, int target)
{
    vector<vector<int>> ans;
    vector<int> inst;
    solve(0, target, cand, ans, inst);
    return ans;
}