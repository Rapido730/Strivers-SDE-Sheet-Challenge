// Problem Link : https://www.codingninjas.com/codestudio/problems/longest-substring-without-repeating-characters_8230684?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
int uniqueSubstrings(string s)
{
    unordered_map<char, int> mp;
    if (s.length() == 1 || s.length() == 0)
        return s.length();
    int left = 0;

    int n = s.length();
    int right = 0;
    int maxi = 0;

    while (right < n)
    {
        if (mp.find(s[right]) != mp.end())
        {
            maxi = max(maxi, right - left);

            while (mp.find(s[right]) != mp.end() && left < right)
            {
                mp.erase(s[left++]);
            }
        }
        mp[s[right]]++;
        right++;
    }
    maxi = max(maxi, right - left);
    return maxi;
}