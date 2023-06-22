// Problem Link : https://www.codingninjas.com/studio/problems/fractional-knapsack_8230767?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

bool static comparator(pair<int, int> &a, pair<int, int> &b)
{
    double a1 = a.second / (double)(a.first);
    double b1 = b.second / (double)(b.first);

    return a1 > b1;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    sort(items.begin(), items.end(), comparator);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (w <= 0)
            break;

        int left = min(w, items[i].first);
        ans += (items[i].second / (double)(items[i].first)) * left;
        w -= left;
    }

    return ans;
}