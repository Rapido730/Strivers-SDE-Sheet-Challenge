// Problem Link : https://www.codingninjas.com/codestudio/problems/day-6-majority-element_8230731?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>

int findMajorityElement(int nums[], int n)
{
    int ele;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            ele = nums[i];
            count++;
        }
        else if (ele == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ele == nums[i])
        {
            count++;
        }
    }

    return (count > n / 2 ? ele : -1);
}