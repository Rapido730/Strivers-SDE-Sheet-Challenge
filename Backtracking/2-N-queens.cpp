// Problem Link : https://leetcode.com/problems/n-queens/

class Solution
{
public:
    vector<vector<string>> ans;
    bool isSafe(vector<string> &cur, int row, int col, int n)
    {
        int c = col;
        int r = row;

        while (c >= 0 && r >= 0)
        {
            if (cur[r][c] == 'Q')
                return false;

            c--;
            r--;
        }

        c = col;
        r = row;

        while (c >= 0 && r >= 0)
        {
            if (cur[r][c] == 'Q')
                return false;

            c--;
        }

        c = col;
        r = row;

        while (c >= 0 && r < n)
        {
            if (cur[r][c] == 'Q')
                return false;

            r++;
            c--;
        }

        return true;
    }
    void solve(int col, vector<string> &cur, int n)
    {
        if (col == n)
        {
            ans.push_back(cur);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(cur, row, col, n))
            {
                cur[row][col] = 'Q';
                solve(col + 1, cur, n);
                cur[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        unordered_map<int, bool> row, col;
        vector<string> cur;
        for (int i = 0; i < n; i++)
        {
            string temp = "";
            for (int j = 0; j < n; j++)
            {
                temp.push_back('.');
            }
            cur.push_back(temp);
        }

        solve(0, cur, n);

        return ans;
    }
};