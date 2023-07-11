//  Problem Link : https://www.codingninjas.com/studio/problems/day-13-print-permutations-string_8230703?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>

vector<string> ans;
void solve(int ind, string s)
{
    if (ind == s.size())
    {
        ans.push_back(s);
    }
    for (int i = ind; i < s.size(); i++)
    {
        swap(s[ind], s[i]);
        solve(ind + 1, s);
        swap(s[ind], s[i]);
    }
}

vector<string> findPermutations(string &s)
{
    solve(0, s);
    return ans;
}