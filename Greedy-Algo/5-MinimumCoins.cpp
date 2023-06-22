// Problem Link : https://www.codingninjas.com/studio/problems/find-minimum-number-of-coins_8230766?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int count = 0;
    for (int it : coins)
    {
        count += (amount / it);
        amount %= it;
    }

    return count;
}
