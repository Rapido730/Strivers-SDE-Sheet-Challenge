// Problem Link : https://www.codingninjas.com/codestudio/problems/unique-paths_8230802?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
int uniquePaths(int m, int n)
{
    vector<int> dp(n, 1);

    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            int ans = (j > 2 ? dp[j - 2] : 1) + dp[j - 1];

            dp[j - 1] = ans;
        }
    }

    return dp[n - 1];
}