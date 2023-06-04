// Problem Link : https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_8230746?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxi = 0;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mini > prices[i])
        {
            mini = prices[i];
        }
        else
        {
            maxi = max(maxi, prices[i] - mini);
        }
    }

    return maxi;
}