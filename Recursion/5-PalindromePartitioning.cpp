// Problem Link : https://www.codingninjas.com/studio/problems/palindrome-partitioning_8230726?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
unordered_map<string, bool> mp;
bool isPalindrome(string s)
{
    if (mp.find(s) != mp.end())
        return mp[s];
    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return mp[s] = true;
}
vector<vector<string>> res;
void solve(vector<string> &cur, int ind, string s)
{
    if (ind == s.size())
    {
        res.push_back(cur);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        string temp = s.substr(ind, i - ind + 1);
        if (isPalindrome(temp))
        {
            cur.push_back(temp);
            solve(cur, i + 1, s);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    vector<string> cur;
    solve(cur, 0, s);
    return res;
}