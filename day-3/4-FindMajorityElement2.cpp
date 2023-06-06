// Problem Link : https://www.codingninjas.com/codestudio/problems/majority-element-ii_8230738?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int ele1, ele2;
    int c1 = 0, c2 = 0;
    int n = arr.size();

    for (int num : arr)
    {
        if (num == ele1)
        {
            c1++;
        }
        else if (num == ele2)
        {
            c2++;
        }
        else if (c1 == 0)
        {
            ele1 = num;
            c1 = 1;
        }
        else if (c2 == 0)
        {
            ele2 = num;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    // cout<<ele1<<ele2<<endl;

    c1 = 0;
    c2 = 0;

    for (int num : arr)
    {
        if (num == ele1)
        {
            c1++;
        }
        if (num == ele2)
        {
            c2++;
        }
    }
    // cout<<c1<<c2;

    vector<int> ans;
    if (c1 > n / 3)
    {
        ans.push_back(ele1);
    }

    if (c2 > n / 3)
    {
        ans.push_back(ele2);
    }

    return ans;
}