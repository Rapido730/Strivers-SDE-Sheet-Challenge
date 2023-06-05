// Problem Link : https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_8230816?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    int fast = arr[0];
    int slow = arr[0];

    do
    {
        fast = arr[arr[fast]];
        slow = arr[slow];
    } while (slow != fast);
    fast = arr[0];
    while (slow != fast)
    {
        fast = arr[fast];
        slow = arr[slow];
    }
    return slow;
}
