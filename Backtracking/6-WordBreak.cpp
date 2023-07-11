// Problem Link : https://www.codingninjas.com/studio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>

bool check(string s, unordered_map<string, bool> &mp)
{
    return mp[s];
}

void solve(string s, vector<string> &dictionary, int ind, string cur, vector<string> &ans, unordered_map<string, bool> &mp)
{
    if (ind >= s.length())
    {
        ans.push_back(cur.substr(1));
        return;
    }

    for (int i = ind; i < s.length(); i++)
    {
        string temp = s.substr(ind, i - ind + 1);
        if (check(temp, mp))
        {
            solve(s, dictionary, i + 1, cur + " " + temp, ans, mp);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dict)
{
    unordered_map<string, bool> mp;

    for (auto it : dict)
    {
        mp[it] = true;
    }
    vector<string> ans;
    string cur = "";

    solve(s, dict, 0, cur, ans, mp);
    return ans;
}