// Problem Link  : https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_8230733?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    long long sn = (n * (n + 1)) / 2;
    long long sn2 = (n * (n + 1) * (2 * n + 1)) / 6;
    long long sum = 0;
    long long sqsum = 0;
    for (long long i : arr)
    {
        sum += i;
        sqsum += i * i;
    }

    long long sub = sum - sn;
    long long sqsub = sqsum - sn2;

    long long add = sqsub / sub;

    long long x = (add - sub) / 2;
    long long y = (add + sub) / 2;

    return {x, y};
}
