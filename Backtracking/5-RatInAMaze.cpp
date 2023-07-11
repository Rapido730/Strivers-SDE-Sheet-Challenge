//  Problem Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution
{
public:
    void solve(vector<vector<int>> &m, int n, int i, int j, vector<string> &ans, string cur)
    {
        if (i >= n || j >= n || i < 0 || j < 0)
            return;

        if (m[i][j] == 0)
            return;

        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(cur);
        }
        int temp = m[i][j];
        m[i][j] = 0;

        solve(m, n, i + 1, j, ans, cur + "D");
        solve(m, n, i - 1, j, ans, cur + "U");
        solve(m, n, i, j + 1, ans, cur + "R");
        solve(m, n, i, j - 1, ans, cur + "L");

        m[i][j] = temp;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;

        solve(m, n, 0, 0, ans, "");
        return ans;
    }
};
